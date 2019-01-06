# $FreeBSD$

PORTNAME=	yesod-core
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CABAL=	aeson>=0.5 auto-update blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 case-insensitive>=0.2 cereal>=0.3 \
		clientsession>=0.9.1 conduit>=1.2 conduit-extra cookie>=0.4.1 \
		data-default deepseq-generics exceptions>=0.6 fast-logger>=2.2 http-types>=0.7 \
		lifted-base>=0.1.2 monad-control>=0.3 monad-logger>=0.3.1 mtl \
		mwc-random old-locale>=1.0.0.2 path-pieces>=0.1.2 \
		primitive random>=1.0.0.2 resourcet>=0.4.9 safe semigroups \
		shakespeare>=2.0 transformers-base>=0.4 unix-compat unliftio \
		unordered-containers>=0.2 vector>=0.9 wai>=3.0 \
		wai-extra>=3.0.5 wai-logger>=0.2 warp>=3.0.2 word8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
