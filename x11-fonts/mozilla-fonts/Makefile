# Ports collection makefile for:	mozilla-fonts
# Date created:				10 Mar 2000
# Whom:					dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	mozilla-fonts
PORTVERSION=	1.0
PORTREVISION=	1

CATEGORIES=	x11-fonts www
MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	dom@happygiraffe.net

USE_X_PREFIX=	true

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts
.endif
	@ ${CAT} ${DESCR}

.include <bsd.port.mk>
