PORTNAME=	panopticum
PORTVERSION=	2.0.0.0
PORTREVISION=	3
CATEGORIES=	ports-mgmt haskell

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Query port information with every combination of OPTIONS
WWW=		https://foss.heptapod.net/bsdutils/panopticum

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITLAB=	yes
GL_SITE=	https://foss.heptapod.net
GL_ACCOUNT=	bsdutils
GL_COMMIT=	ef5c3793acad2ed2ef17138dabfeb575e26458c5

USE_CABAL=	ansi-terminal-1.0 \
		ansi-terminal-types-0.11.5_1 \
		ansi-wl-pprint-0.6.9_4 \
		async-2.2.4_3 \
		clock-0.8.3 \
		colour-2.3.6 \
		extra-1.7.13 \
		hashable-1.4.2.0_1 \
		optparse-applicative-0.17.0.0 \
		safe-exceptions-0.1.7.3 \
		transformers-compat-0.7.2 \
		unliftio-0.2.24.0 \
		unliftio-core-0.2.1.0_2

.include <bsd.port.mk>
