# $FreeBSD$

PORTNAME=	yesod-auth
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication for Yesod

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CABAL=	aeson>=0.7 authenticate>=1.3 base16-bytestring \
		base64-bytestring blaze-builder blaze-html>=0.5 \
		blaze-markup>=0.5.1 byteable conduit conduit-extra cryptohash \
		data-default email-validate>=1.0 file-embed http-client \
		http-conduit>=1.5 http-types lifted-base>=0.1 mime-mail>=0.3 \
		network>=2.6 network-uri>=2.6 nonce>=1.0.2 persistent>=2.1 \
		persistent-template>=2.1 random>=1.0.0.2 resourcet safe \
		shakespeare unordered-containers wai>=1.4 \
		yesod-core>=1.4 yesod-form>=1.4 yesod-persistent>=1.4

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
