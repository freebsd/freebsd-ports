PORTNAME=	cabal2tuple
PORTVERSION=	2.0.0.1
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
USE_CABAL=	hashable-1.4.2.0
USE_CABAL+=	OneTuple-0.4.1.1 \
                QuickCheck-2.14.2 \
                StateVar-1.2.2 \
                aeson-2.1.2.1_1 \
                ansi-terminal-0.11.4 \
                ansi-wl-pprint-0.6.9_3 \
                assoc-1.0.2_3 \
                async-2.2.4_2 \
                attoparsec-0.14.4_3 \
                base-compat-0.12.2 \
                base-compat-batteries-0.12.2 \
                base-orphans-0.8.8.2 \
                base16-bytestring-1.0.2.0 \
                bifunctors-5.5.15 \
                boring-0.2_2 \
                cabal-plan-0.7.2.3 \
                colour-2.3.6 \
                comonad-5.0.8_1 \
                contravariant-1.5.5 \
                data-array-byte-0.1.0.1_1 \
                data-fix-0.3.2_3 \
                dec-0.0.5 \
                distributive-0.6.2.1_1 \
                dlist-1.0 \
                generically-0.1.1 \
                indexed-profunctors-0.1.1 \
                indexed-traversable-0.1.2_2 \
                indexed-traversable-instances-0.1.1.2 \
                integer-logarithms-1.0.3.1_4 \
                optics-core-0.4.1_1 \
                optparse-applicative-0.17.0.0 \
                primitive-0.8.0.0 \
                random-1.2.1.1 \
                scientific-0.3.7.0_4 \
                semialign-1.2.0.1_3 \
                semigroupoids-5.3.7_1 \
                singleton-bool-0.1.6_2 \
                some-1.0.4.1 \
                splitmix-0.1.0.4_2 \
                strict-0.4.0.1_4 \
                tagged-0.8.7 \
                text-short-0.1.5_1 \
                th-abstraction-0.5.0.0 \
                these-1.1.1.1_6 \
                time-compat-1.9.6.1_4 \
                topograph-1.0.0.2 \
                transformers-compat-0.7.2 \
                unordered-containers-0.2.19.1_1 \
                uuid-types-1.0.5_3 \
                vector-0.13.0.0_3 \
                vector-stream-0.1.0.0_2 \
                witherable-0.4.2_4

.include <bsd.port.mk>
