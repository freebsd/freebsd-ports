PORTNAME=	cgrep
PORTVERSION=	6.6.32
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Context-aware grep for source codes
WWW=		https://awgn.github.io/cgrep/

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cabal pkgconfig

USE_CABAL=	OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		aeson-2.1.1.0 \
		ansi-terminal-0.11.3 \
		assoc-1.0.2_3 \
		async-2.2.4_2 \
		attoparsec-0.14.4_2 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.7 \
		bifunctors-5.5.13 \
		bitvec-1.1.3.0 \
		clock-0.8.3 \
		cmdargs-0.10.21 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		either-5.0.2 \
		extra-1.7.12 \
		generically-0.1 \
		hashable-1.4.1.0 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_3 \
		libyaml-0.1.2_1 \
		mono-traversable-1.0.15.3 \
		primitive-0.7.4.0 \
		profunctors-5.6.2_2 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-pcre-0.95.0.0_4 \
		regex-posix-0.96.0.1_1 \
		resourcet-1.3.0 \
		safe-0.3.19 \
		scientific-0.3.7.0_3 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_1 \
		strict-0.4.0.1_4 \
		stringsearch-0.3.6.6_1 \
		tagged-0.8.6.1_3 \
		text-short-0.1.5_1 \
		th-abstraction-0.4.5.0 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		transformers-compat-0.7.2 \
		unicode-show-0.1.1.1 \
		unix-compat-0.6_1 \
		unliftio-core-0.2.0.1_2 \
		unordered-containers-0.2.19.1_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_3 \
		vector-0.13.0.0_1 \
		vector-algorithms-0.9.0.1_1 \
		vector-stream-0.1.0.0_1 \
		witherable-0.4.2_3 \
		yaml-0.11.8.0_2

CONFLICTS_INSTALL=	codesearch

.include <bsd.port.mk>
