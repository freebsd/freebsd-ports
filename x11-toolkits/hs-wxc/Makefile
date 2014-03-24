# $FreeBSD$

PORTNAME=	wxc
PORTVERSION=	0.90.0.4
PORTREVISION=	7
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	wxHaskell C++ wrapper

USE_CABAL=	wxdirect>=0.90

USE_WX=		3.0
WX_COMPS=	wx
WX_UNICODE=	yes

NOPORTDOCS=	yes
USE_DOS2UNIX=	yes

post-patch::
	@${REINPLACE_CMD} 's|"wx-config"|"wxgtk2u-2.9-config"| ; \
	    s|/sbin/ldconfig -n|/sbin/ldconfig -m| ' ${WRKSRC}/Setup.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
