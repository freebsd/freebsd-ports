# New ports collection makefile for:    apache mod_log_mysql
# Date created:		2001/11/22
# Whom:			lev@serebryakov.spb.ru
#
# $FreeBSD$

PORTNAME=	mod_log_mysql
PORTVERSION=	1.16
CATEGORIES=	www databases
MASTER_SITES=	http://www.grubbybaby.com/mod_log_sql/
DISTFILES=	mod_log_sql-${PORTVERSION}

MAINTAINER=	lev@serebryakov.spb.ru

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/${AP_PORT}
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/${AP_PORT}

WRKSRC=		${WRKDIR}/${PORTNAME}

AP_PORT?=	www/apache13
APXS?=		${LOCALBASE}/sbin/apxs

# Here is no mod_ssl by default
HAVE_MOD_SSL=

MOD_SSL_HEADER=	${LOCALBASE}/include/apache/mod_ssl.h

.if exists(${MOD_SSL_HEADER})
do-configure:
	@${ECHO_MSG} "Make with mod_ssl support"
.else
do-configure:
	@${ECHO_MSG} "Make without mod_ssl support"
	@${PERL} -pi -e 's/#define WANT_SSL_LOGGING/#undef WANT_SSL_LOGGING/' ${WRKSRC}/mod_log_mysql.c
.endif

do-build:
	@cd ${WRKSRC} && ${APXS} -c -o ${PORTNAME}.so -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib/mysql -lmysqlclient ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${APXS} -i -n${PORTNAME:S/^mod_//}  -A ${PORTNAME}.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CONFIGURATION INSTALL README access_log.sql make_combined_log.pl
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
