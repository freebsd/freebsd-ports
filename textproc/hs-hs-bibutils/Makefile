# $FreeBSD$

PORTNAME=	hs-bibutils
PORTVERSION=	4.15
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell bindings to bibutils, the bibliography conversion utilities

LICENSE=	GPLv2

BUILD_DEPENDS=	bibutils>=4.9:${PORTSDIR}/textproc/bibutils
RUN_DEPENDS=	bibutils>=4.9:${PORTSDIR}/textproc/bibutils

USE_CABAL=	syb

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
