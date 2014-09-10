# $FreeBSD$

PORTNAME=	gitit
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Wiki using happstack, git or darcs, and pandoc

LICENSE=	GPLv2

USE_CABAL=	aeson>=0.7 base64-bytestring>=0.1 blaze-html>=0.4 \
		ConfigFile>=1 feed>=0.3.6 filestore>=0.6 \
		happstack-server>=7.0 highlighting-kate>=0.5.0.1 \
		hoauth2>=0.4.1 hslogger>=1 HStringTemplate>=0.6 HTTP>=4000.0 \
		http-client>=0.3.5 http-client-tls>=0.2.2 json>=0.4 mtl \
		network>=2 pandoc>=1.12.4 pandoc-types>=1.12.3 parsec random \
		recaptcha>=0.1 safe SHA>1 split syb tagsoup>=0.13 text \
		uri>=0.1 url>=2.1 utf8-string>=0.3 xml>=1.3.5 \
		xss-sanitize>=0.3 zlib>=0.5

EXECUTABLE=	expireGititCache gitit

FLAGS_DEFINE=	PLUGINS
FLAGS_DEFAULT=	PLUGINS

PLUGINS_DESC=		Enable support for plugins
PLUGINS_FLAG_ENABLE=	plugins
PLUGINS_FLAG_CABAL=	ghc-paths

FLAGS_DISABLE=		network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
