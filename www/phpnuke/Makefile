# New ports collection makefile for:	phpnuke
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	phpnuke
PORTVERSION=	5.3.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	PHP-Nuke-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.if defined(WITH_PHP4)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOCS=		ADDONS-MODULES BLOCKS CHANGES README TODO

pre-everything:
.if !defined(WITH_PHP4)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITH_PHP4 if you want to use PHP Nuke with PHP4."
	@${ECHO_MSG} ""
.endif

do-install:
	@${MKDIR} ${PREFIX}/www/phpnuke
	@${MKDIR} ${PREFIX}/www/phpnuke/html
	@${MKDIR} ${PREFIX}/www/phpnuke/sql
	@${CP} -Rp ${WRKDIR}/html ${WRKDIR}/sql ${PREFIX}/www/phpnuke
.if !defined(NOPORTDOCS)
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKDIR}/${FILE} ${PREFIX}/www/phpnuke
.endfor
.endif

.include <bsd.port.mk>
