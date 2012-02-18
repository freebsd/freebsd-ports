# New ports collection makefile for: hs-yesod-core
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-core
PORTVERSION=	0.9.4.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	BSD

USE_CABAL=	aeson>=0.3 blaze-builder>=0.2.1.4 blaze-html>=0.4.1.3 \
		case-insensitive>=0.2 cereal>=0.3 clientsession>=0.7.3.1 \
		cookie>=0.3 data-object>=0.3 data-object-yaml>=0.3 \
		enumerator>=0.4.8 failure>=0.1 fast-logger>=0.0.1 \
		hamlet>=0.10.6 http-types>=0.6.5 monad-control>=0.2 \
	    	parsec>=2 path-pieces>=0.0 shakespeare>=0.10 \
	    	shakespeare-css>=0.10.5 shakespeare-i18n \
	    	shakespeare-js>=0.10.4 text>=0.7 transformers>=0.2.2 \
	    	transformers-base>=0.4 vector>=0.9 wai>=0.4 wai-extra>=0.4.1 \
	    	wai-logger>=0.0.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
