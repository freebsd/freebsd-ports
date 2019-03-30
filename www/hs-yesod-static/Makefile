# $FreeBSD$

PORTNAME=	yesod-static
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Static file serving subsite for Yesod Web Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	async attoparsec>=0.10 base64-bytestring>=0.1.0.1 \
		blaze-builder>=0.3 byteable>=0.1 conduit>=0.5 conduit-extra \
		cryptohash>=0.11 cryptohash-conduit>=0.1 cryptonite-conduit \
		css-text>=0.1.2 data-default file-embed>=0.0.4.1 hashable>=1.1 \
		hjsmin http-types>=0.7 mime-types>=0.1 old-time>=1.0 \
		resourcet>=0.4 unix-compat>=0.2 unordered-containers>=0.2 \
		wai>=1.3 wai-app-static>=3.1 yesod-core>=1.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
