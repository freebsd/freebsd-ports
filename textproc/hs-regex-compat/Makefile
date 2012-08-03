# New ports collection makefile for: hs-regex-compat
# Date created:        August 18, 2010
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	regex-compat
PORTVERSION=	0.95.1
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Replaces/Enhances Text.Regex

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	regex-base>=0.93 regex-posix>=0.95.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
