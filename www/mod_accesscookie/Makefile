# New ports collection makefile for:	mod_accessCookie
# Date created:			Apr 16 2004
# Whom:				Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_accessCookie
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	http://etweb.wkv.at/himself/Programming/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Supply access control based cookies stored in a MySQL database

USE_MYSQL=	YES
WANT_APACHE=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=	README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.post.mk>
