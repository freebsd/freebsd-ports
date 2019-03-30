# $FreeBSD$

PORTNAME=	wxdirect
PORTVERSION=	0.92.3.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Helper tool for building wxHaskell

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USES=		dos2unix
USE_CABAL=	strict

EXECUTABLE=	wxdirect

post-patch::
	@${REINPLACE_CMD} 's|"wx-config"|"wxgtk2u-3.0-config"|' \
	    ${WRKSRC}/src/ParseC.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
