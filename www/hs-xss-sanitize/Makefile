# $FreeBSD$

PORTNAME=	xss-sanitize
PORTVERSION=	0.3.3
PORTREVISION=	3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Sanitize untrusted HTML to prevent XSS attacks

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10.0.3 css-text>=0.1.1 network>=2 \
		tagsoup>=0.12.2 text>=0.11 utf8-string>=0.3

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
