# New ports collection makefile for:	mod_vdbh
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_vdbh
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://www.synthemesc.com/downloads/mod_vdbh/
DIST_SUBDIR=	apache

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Allows mass virtual hosting using a MySQL backend with Apache 2.0.x

USE_APACHE=	YES
WITH_APACHE2=	YES

USE_MYSQL=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
APXS?=		${LOCALBASE}/sbin/apxs
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
