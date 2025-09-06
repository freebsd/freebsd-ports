PORTNAME=	cgrep
PORTVERSION=	8.1.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Context-aware grep for source codes
WWW=		https://awgn.github.io/cgrep/

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cabal pkgconfig

USE_CABAL=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		aeson-2.2.1.0_1 \
		ansi-terminal-1.1 \
		ansi-terminal-types-1.1 \
		assoc-1.1_1 \
		async-2.2.5 \
		atomic-primops-0.8.5 \
		attoparsec-0.14.4_5 \
		base-orphans-0.9.1 \
		bifunctors-5.6.1_2 \
		bitarray-0.0.1.1_1 \
		bitvec-1.1.5.0 \
		bitwise-1.0.0.1_9 \
		bytestring-strict-builder-0.4.5.7 \
		clock-0.8.4 \
		cmdargs-0.10.22 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		conduit-1.3.5 \
		contravariant-1.5.5 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		either-5.0.2_1 \
		extra-1.7.14 \
		generically-0.1.1_2 \
		hashable-1.4.3.0_1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		libyaml-0.1.2_1 \
		mmap-0.5.9 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.3 \
		network-uri-2.6.4.2_1 \
		posix-paths-0.3.0.0 \
		primitive-0.9.0.0 \
		profunctors-5.6.2_3 \
		random-1.2.1.2 \
		rawfilepath-1.1.0 \
		regex-base-0.94.0.2_4 \
		regex-pcre-0.95.0.0_6 \
		regex-posix-0.96.0.1_3 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		split-0.2.5 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		stringsearch-0.3.6.6_1 \
		tagged-0.8.8 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_1 \
		th-compat-0.1.4_4 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-compat-0.7.2 \
		unagi-chan-0.4.1.4 \
		unicode-show-0.1.1.1 \
		unix-compat-0.7.1 \
		unliftio-0.2.25.0 \
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.20_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-algorithms-0.9.0.1_3 \
		vector-stream-0.1.0.1 \
		witherable-0.4.2_4 \
		yaml-0.11.11.2_2

CONFLICTS_INSTALL=	codesearch

.include <bsd.port.mk>
