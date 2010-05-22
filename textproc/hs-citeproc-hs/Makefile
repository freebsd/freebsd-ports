# New ports collection makefile for: hs-citeproc-hs
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	citeproc-hs
PORTVERSION=	0.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Citation Style Language implementation in Haskell

USE_HACKAGE=	hxt>=8.1

PORTDATA=	*

OPTIONS=	BIBUTILS "Use Chris Putnam's Bibutils" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_BIBUTILS)
CONFIGURE_ARGS+=	--flags="bibutils"
USE_HACKAGE+=		hs-bibutils
.else
CONFIGURE_ARGS+=	--flags="-bibutils"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
