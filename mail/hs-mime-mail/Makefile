# $FreeBSD$

PORTNAME=	mime-mail
PORTVERSION=	0.4.14
PORTREVISION=	2
CATEGORIES=	mail haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compose MIME email messages

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	base64-bytestring>=0.1 blaze-builder>=0.2.1 random>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
