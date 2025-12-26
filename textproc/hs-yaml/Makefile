PORTNAME=	yaml
PORTVERSION=	0.11.11.2
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Utilities for converting YAML and JSON documents back and forth
WWW=		https://github.com/snoyberg/yaml/

LICENSE=	BSD3CLAUSE

USES=		cabal

CONFLICTS_INSTALL=	json2yaml # bin/json2yaml

USE_CABAL=	OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		StateVar-1.2.2 \
		aeson-2.2.3.0_4 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_1 \
		attoparsec-0.14.4_6 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_2 \
		bitvec-1.1.5.0_3 \
		character-ps-0.1 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		conduit-1.3.6.1 \
		contravariant-1.5.5 \
		data-fix-0.3.4_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		generically-0.1.1_4 \
		hashable-1.5.0.0_1 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		libyaml-0.1.4 \
		libyaml-clib-0.2.5 \
		mono-traversable-1.0.21.0 \
		network-uri-2.6.4.2_1 \
		optparse-applicative-0.19.0.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		random-1.3.1 \
		resourcet-1.3.0 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		split-0.2.5 \
		splitmix-0.1.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.10 \
		tasty-1.5.3_2 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		transformers-compat-0.7.2 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.21_1 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_2 \
		vector-algorithms-0.9.1.0 \
		vector-stream-0.1.0.1_4 \
		witherable-0.5_1

CABAL_EXECUTABLES=	json2yaml yaml2json
CABAL_FLAGS=		-no-exe
CABAL_REVISION=		2

.include <bsd.port.mk>
