# New ports collection makefile for:    apache mod_log_sql
# Date created:		2001/11/22
# Whom:			lev@serebryakov.spb.ru
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.18
PORTREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

MAKE_JOBS_SAFE=  yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_MYSQL=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_APACHE=	1.3

ALL_TARGET=	dso
INSTALL_TARGET=	dsoinstall

PORTDOCS=	LICENSE CHANGELOG create_tables.sql make_combined_log.pl \
			documentation.ps documentation.txt README FreeBSD-readme.txt \
			HTML

do-configure:
	@${REINPLACE_CMD} "s|^APACHEINSTALLED = .*\$$|APACHEINSTALLED = ${LOCALBASE}|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^APACHEHEADERS   = .*\$$|APACHEHEADERS   = ${LOCALBASE}/include/apache|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^APXS            = .*\$$|APXS            = ${APXS}|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^MYSQLLIBRARIES  = .*\$$|MYSQLLIBRARIES  = ${LOCALBASE}/lib/mysql|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^MYSQLHEADERS    = .*\$$|MYSQLHEADERS    = ${LOCALBASE}/include/mysql|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|sql_log_module|log_sql_module|g" ${WRKSRC}/${PORTNAME}.c

post-install:
	${APXS} -e -a -n log_sql ${LOCALBASE}/${APACHEMODDIR}/${PORTNAME}.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${MKDIR} ${DOCSDIR}/HTML/
	@${INSTALL_DATA} ${FILESDIR}/FreeBSD-readme.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/create_tables.sql ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/Documentation/documentation.ps ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/Documentation/documentation.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/Documentation/README ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/Documentation/HTML/* ${DOCSDIR}/HTML/
	@${INSTALL_SCRIPT} ${WRKSRC}/make_combined_log.pl ${DOCSDIR}/
.endif

.include <bsd.port.mk>
