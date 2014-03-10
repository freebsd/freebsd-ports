# $FreeBSD$

PORTNAME=	hs-bibutils
PORTVERSION=	5.0
PORTREVISION=	3
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings to bibutils, the bibliography conversion utilities

LICENSE=	GPLv2

BUILD_DEPENDS=	bibutils>=5.0:${PORTSDIR}/textproc/bibutils
RUN_DEPENDS=	bibutils>=5.0:${PORTSDIR}/textproc/bibutils

USE_CABAL=	syb

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
