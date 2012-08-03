# New ports collection makefile for: hs-html-conduit
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	html-conduit
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse HTML documents using xml-conduit datatypes

LICENSE=	MIT

CABAL_SETUP=	Setup.hs

USE_CABAL=	conduit>=0.4 filesystem-conduit>=0.4 resourcet>=0.3 \
		system-filepath>=0.4 tagstream-conduit>=0.3 text \
		transformers xml-conduit>=0.7 xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
