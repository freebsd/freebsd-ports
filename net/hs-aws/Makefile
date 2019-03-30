# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Amazon Web Services (AWS) for Haskell

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson>=0.6 attoparsec>=0.11 base16-bytestring \
		base64-bytestring blaze-builder>=0.2.1.4 byteable \
		case-insensitive>=0.2 cereal>=0.3 conduit>=1.1 \
		conduit-extra>=1.1 cryptohash>=0.11 data-default>=0.5.3 \
		http-conduit>=2.1 http-types>=0.7 lifted-base>=0.1 \
		monad-control>=0.3 mtl network resourcet>=1.1 safe>=0.3 \
		scientific>=0.3 tagged>=0.7 unordered-containers>=0.2 \
		utf8-string>=0.3 vector>=0.10 xml-conduit>=1.2

FLAGS_DISABLE=	examples

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
