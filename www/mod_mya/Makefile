# New ports collection makefile for:	mod_mya
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_mya
PORTVERSION=	3.0.1
CATEGORIES=	www
MASTER_SITES=	http://www.synthemesc.com/downloads/mod_mya/
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows basic authentication data to be stored in a MySQL database

USE_APACHE=	YES
WITH_APACHE2=	YES

USE_MYSQL=		YES
WANT_MYSQL_VER=	323

MYSQL_INC?=	${LOCALBASE}/include/mysql
MYSQL_LIB?=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=	AUTHORS README TODO

do-build:
	@(cd ${WRKSRC} && ${APXS} -I ${MYSQL_INC} -L ${MYSQL_LIB} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -i -A -n ${PORTNAME:S/mod_//} ${PORTNAME}.la)

.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
