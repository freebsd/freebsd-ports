# New ports collection makefile for:	mod_auth_mysql41_ap2
# Date Created:				Thu Oct  2 10:33:50 CDT 2003
# Whom:					Douglas A. Maske <maske@maske.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_mysql41_ap2
PORTVERSION=	1.00
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.maske.org/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	maske@maske.org
COMMENT=	MySQL 4.1 and Apache 2 port of mod_auth_mysql

USE_APACHE=	YES
WITH_APACHE2=	YES

USE_MYSQL=	YES
WANT_MYSQL_VER=	41
MYSQL_INC?=	${LOCALBASE}/include/mysql
MYSQL_LIB?=	${LOCALBASE}/lib/mysql -lmysqlclient

MODULE_NAME=	mod_auth_mysql
PORTDOCS=	README

do-build:
	@(cd ${WRKSRC} && ${APXS} -D APACHE2 -I ${MYSQL_INC} -L ${MYSQL_LIB} -c ${MODULE_NAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -i -A -n ${MODULE_NAME:S/mod_//} ${MODULE_NAME}.la)
.if !defined(NORPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
