# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgrep
PORTVERSION=	6.6.32
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Context-aware grep for source codes

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cabal pkgconfig

USE_CABAL=	StateVar-1.2 \
		aeson-1.4.7.1_1 \
		ansi-terminal-0.10.3 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		bifunctors-5.5.7 \
		cabal-doctest-1.0.8_1 \
		clock-0.8 \
		cmdargs-0.10.20 \
		colour-2.3.5 \
		comonad-5.0.6 \
		conduit-1.3.2 \
		contravariant-1.5.2 \
		distributive-0.6.2 \
		dlist-0.8.0.8 \
		either-5.0.1.1_1 \
		exceptions-0.10.4_1 \
		extra-1.7.1 \
		hashable-1.3.0.0_1 \
		integer-logarithms-1.0.3_2 \
		libyaml-0.1.2 \
		mono-traversable-1.0.15.1 \
		primitive-0.7.0.1 \
		profunctors-5.5.2 \
		random-1.1_1 \
		regex-base-0.94.0.0_1 \
		regex-pcre-0.95.0.0_1 \
		regex-posix-0.96.0.0_1 \
		resourcet-1.2.4 \
		safe-0.3.18_1 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.4 \
		semigroups-0.19.1 \
		split-0.2.3.4 \
		stringsearch-0.3.6.6_1 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		time-compat-1.9.3 \
		transformers-compat-0.6.5 \
		unicode-show-0.1.0.4 \
		unix-compat-0.5.2_1 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.10.0_1 \
		utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		yaml-0.11.3.0

CONFLICTS_INSTALL=	codesearch

.include <bsd.port.mk>
