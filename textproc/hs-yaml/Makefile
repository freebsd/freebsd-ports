# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	0.11.3.0
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Utilities for converting YAML and JSON documents back and forth

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	aeson-1.4.6.0 \
		attoparsec-0.13.2.3_1 \
		base-compat-0.11.1 \
		base-orphans-0.8.2 \
		conduit-1.3.1.2 \
		dlist-0.8.0.7 \
		exceptions-0.10.4 \
		hashable-1.3.0.0 \
		integer-logarithms-1.0.3_2 \
		libyaml-0.1.2 \
		mono-traversable-1.0.15.1 \
		primitive-0.7.0.1 \
		random-1.1_1 \
		resourcet-1.2.3 \
		scientific-0.3.6.2 \
		split-0.2.3.4 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		time-compat-1.9.3 \
		unliftio-core-0.2.0.1 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3

EXECUTABLES=	json2yaml yaml2json
CABAL_FLAGS=	-no-exe

.include <bsd.port.mk>
