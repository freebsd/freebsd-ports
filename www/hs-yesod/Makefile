# $FreeBSD$

PORTNAME=	yesod
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson blaze-html>=0.5 blaze-markup>=0.5.1 conduit-extra \
		data-default fast-logger monad-control>=0.3 monad-logger \
		safe shakespeare>=2.0 streaming-commons \
		unordered-containers wai>=1.3 wai-extra>=1.3 wai-logger \
		warp>=1.3 yaml yesod-auth>=1.4 yesod-core>=1.4 \
		yesod-form>=1.3 yesod-persistent>=1.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
