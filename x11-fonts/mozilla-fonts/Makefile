# Ports collection makefile for:	mozilla-fonts
# Date created:				10 Mar 2000
# Whom:					dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	mozilla-fonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts www
MASTER_SITES=	http://fox.mit.edu/skunk/xwin/
DISTNAME=	${PORTNAME}

MAINTAINER=	dom@myrddin.demon.co.uk

ALL_TARGET=	pcf

USE_X_PREFIX=	true

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts
.endif
	@ ${CAT} ${DESCR}

.include <bsd.port.mk>
