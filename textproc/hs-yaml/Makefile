# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	0.11.0.0
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Utilities for converting YAML and JSON documents back and forth

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	aeson-1.4.2.0_1 attoparsec-0.13.2.2 base-compat-0.10.5 \
		conduit-1.3.1 dlist-0.8.0.5 exceptions-0.10.0_2 \
		hashable-1.2.7.0_1 integer-logarithms-1.0.2.2 libyaml-0.1.1.0 \
		mono-traversable-1.0.11.0 primitive-0.6.4.0_1 random-1.1_1 \
		resourcet-1.2.2 scientific-0.3.6.2 split-0.2.3.3_1 tagged-0.8.6 \
		th-abstraction-0.2.10.0 time-locale-compat-0.1.1.5 \
		transformers-compat-0.6.2 unliftio-core-0.1.2.0_1 \
		unordered-containers-0.2.10.0 uuid-types-1.0.3_1 vector-0.12.0.2 \
		vector-algorithms-0.8.0.1

EXECUTABLES=	json2yaml yaml2json
CABAL_FLAGS=	-no-exe

.include <bsd.port.mk>
