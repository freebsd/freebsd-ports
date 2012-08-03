# New ports collection makefile for: hs-xss-sanitize
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xss-sanitize
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Sanitize untrusted HTML to prevent XSS attacks

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10.0.3 css-text>=0.1.1 network>=2 \
		tagsoup>=0.12.2 text>=0.11 utf8-string>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
