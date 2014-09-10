# $FreeBSD$

PORTNAME=	yesod-auth
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication for Yesod

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 authenticate>=1.3 base16-bytestring \
		base64-bytestring blaze-builder blaze-html>=0.5 \
		blaze-markup>=0.5.1 byteable conduit conduit-extra cryptohash \
		data-default email-validate>=1.0 file-embed http-client \
		http-conduit>=1.5 http-types lifted-base>=0.1 mime-mail>=0.3 \
		network persistent>=1.2 persistent-template>=1.2 \
		random>=1.0.0.2 resourcet safe shakespeare text>=0.7 \
		unordered-containers wai>=1.4 yesod-core>=1.2 yesod-form>=1.3 \
		yesod-persistent>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
