PORTNAME=	yaml
PORTVERSION=	0.11.11.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Utilities for converting YAML and JSON documents back and forth
WWW=		https://github.com/snoyberg/yaml/

LICENSE=	BSD3CLAUSE

USES=		cabal

CONFLICTS_INSTALL=	json2yaml # bin/json2yaml

USE_CABAL=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.2.1.0_1 \
		ansi-terminal-1.0.2 \
		ansi-terminal-types-0.11.5_1 \
		assoc-1.1_1 \
		attoparsec-0.14.4_5 \
		base-orphans-0.9.1 \
		bifunctors-5.6.1_2 \
		bitvec-1.1.5.0 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		conduit-1.3.5 \
		contravariant-1.5.5 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		foldable1-classes-compat-0.1_4 \
		generically-0.1.1_2 \
		hashable-1.4.3.0_1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		libyaml-0.1.2_1 \
		mono-traversable-1.0.15.3 \
		network-uri-2.6.4.2_1 \
		optparse-applicative-0.18.1.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0 \
		random-1.2.1.1_1 \
		resourcet-1.3.0 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		split-0.2.5 \
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
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.20_1 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-algorithms-0.9.0.1_3 \
		vector-stream-0.1.0.1 \
		witherable-0.4.2_4

CABAL_EXECUTABLES=	json2yaml yaml2json
CABAL_FLAGS=		-no-exe
CABAL_REVISION=		2

.include <bsd.port.mk>
