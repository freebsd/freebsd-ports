# New ports collection makefile for:    apache mod_log_sql
# Date created:		2001/11/22
# Whom:			lev@serebryakov.spb.ru
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.18
PORTREVISION=	2
CATEGORIES=	www databases
MASTER_SITES=	http://www.grubbybaby.com/mod_log_sql/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/${APACHE_PORT}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

ALL_TARGET=	dso
INSTALL_TARGET=	dsoinstall

do-configure:
	@${REINPLACE_CMD} "s|^APACHEINSTALLED = .*\$$|APACHEINSTALLED = ${LOCALBASE}|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^APACHEHEADERS   = .*\$$|APACHEHEADERS   = ${LOCALBASE}/include/apache|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^APXS            = .*\$$|APXS            = ${APXS}|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^MYSQLLIBRARIES  = .*\$$|MYSQLLIBRARIES  = ${LOCALBASE}/lib/mysql|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^MYSQLHEADERS    = .*\$$|MYSQLHEADERS    = ${LOCALBASE}/include/mysql|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|sql_log_module|log_sql_module|g" ${WRKSRC}/${PORTNAME}.c

post-install:
	${APXS} -e -a -n log_sql ${LOCALBASE}/libexec/apache/${PORTNAME}.so
	@${MKDIR} ${LOCALBASE}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${LOCALBASE}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${LOCALBASE}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/create_tables.sql ${LOCALBASE}/share/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/make_combined_log.pl ${LOCALBASE}/share/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}/HTML
	@${INSTALL_DATA} ${FILESDIR}/FreeBSD-readme.txt ${LOCALBASE}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/Documentation/documentation.ps ${LOCALBASE}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/Documentation/documentation.txt ${LOCALBASE}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/Documentation/README ${LOCALBASE}/share/doc/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/Documentation/HTML/* ${LOCALBASE}/share/doc/${PORTNAME}/HTML/

.endif

.include <bsd.port.mk>
