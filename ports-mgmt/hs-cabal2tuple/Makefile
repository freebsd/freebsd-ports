PORTNAME=	cabal2tuple
PORTVERSION=	2.0.0.1
PORTREVISION=	2
CATEGORIES=	ports-mgmt haskell

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Generate USE_CABAL and GH_TUPLE knobs for Haskell ports
WWW=		https://foss.heptapod.net/bsdutils/cabal2tuple

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITLAB=	yes
GL_SITE=	https://foss.heptapod.net
GL_ACCOUNT=	bsdutils
GL_TAGNAME=	7adf07b805d83040e7b164c69636c9b67a6a5fc6

# Version of the 'hashable' package should be the same as in devel/hs-cabal-install
USE_CABAL=	hashable-1.4.6.0
USE_CABAL+=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.2.1.0_1 \
		ansi-terminal-1.1 \
		ansi-terminal-types-1.1 \
		assoc-1.1_1 \
		base-orphans-0.9.1 \
		base16-bytestring-1.0.2.0_1 \
		bifunctors-5.6.1_2 \
		cabal-plan-0.7.3.0_2 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		contravariant-1.5.5 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		generically-0.1.1_2 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		network-uri-2.6.4.2_1 \
		optparse-applicative-0.18.1.0 \
		os-string-2.0.3 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0 \
		random-1.2.1.2 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		tagged-0.8.8 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_1 \
		th-compat-0.1.4_4 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20_1 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-stream-0.1.0.1 \
		witherable-0.4.2_4

.include <bsd.port.mk>
