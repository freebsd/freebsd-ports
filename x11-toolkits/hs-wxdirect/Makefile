# $FreeBSD$

PORTNAME=	wxdirect
PORTVERSION=	0.90.1.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Helper tool for building wxHaskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	parsec>=2.1.0 strict

EXECUTABLE=	wxdirect

post-patch::
	@${REINPLACE_CMD} 's|"wx-config"|"wxgtk2u-3.0-config"|' \
	    ${WRKSRC}/src/ParseC.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
