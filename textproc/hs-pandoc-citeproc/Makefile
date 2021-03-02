# $FreeBSD$

PORTNAME=	pandoc-citeproc
PORTVERSION=	0.17.0.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Supports using pandoc with citeproc

LICENSE=	BSD3CLAUSE

DEPRECATED=	Integrated into textproc/hs-pandoc
EXPIRATION_DATE=2021-04-02

USES=		cabal

OPTIONS_DEFINE=		BIBUTILS EMBED_DATA UNICODE_COLLATION
OPTIONS_DEFAULT=	BIBUTILS

BIBUTILS_DESC=		Use Chris Putnam's Bibutils
BIBUTILS_CABAL_FLAGS=	bibutils
BIBUTILS_USE_CABAL=	hs-bibutils-6.10.0.0

EMBED_DATA_DESC=	Embed locale files into the library
EMBED_DATA_CABAL_FLAGS=	embed_data_files
EMBED_DATA_USE_CABAL=	file-embed-0.0.12.0

UNICODE_COLLATION_DESC=		Use bindings to the Internationl Components for Unicode libraries
UNICODE_COLLATION_CABAL_FLAGS=	unicode_collation
UNICODE_COLLATION_USE_CABAL=	text-icu-0.7.0.1
UNICODE_COLLATION_LIB_DEPENDS=	libicui18n.so:devel/icu
UNICODE_COLLATION_EXTRA_PATCHES=${PATCHDIR}/extra-patch-icu68

USE_CABAL=	Glob-0.10.0_1 \
		HTTP-4000.3.14_1 \
		HsYAML-0.2.1.0_1 \
		HsYAML-aeson-0.2.0.0_1 \
		JuicyPixels-3.3.5 \
		QuickCheck-2.14_1 \
		SHA-1.6.4.4 \
		aeson-1.4.7.1_1 \
		aeson-pretty-0.8.8 \
		ansi-terminal-0.10.3 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		base16-bytestring-0.1.1.7 \
		base64-bytestring-1.1.0.0 \
		basement-0.0.11_2 \
		bitarray-0.0.1.1_1 \
		blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.2 \
		blaze-markup-0.8.2.7 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		cmark-gfm-0.2.1 \
		colour-2.3.5 \
		conduit-1.3.2 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		cookie-0.4.5 \
		cryptonite-0.27 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		digest-0.0.1.2 \
		dlist-0.8.0.8 \
		doclayout-0.3 \
		doctemplates-0.8.2 \
		emojis-0.1 \
		errors-2.3.0 \
		haddock-library-1.9.0 \
		hashable-1.3.0.0_1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.7 \
		hslua-1.1.2 \
		hslua-module-system-0.2.1 \
		hslua-module-text-0.2.1 \
		http-client-0.7.1 \
		http-client-tls-0.3.5.3_1 \
		http-types-0.12.3 \
		hxt-9.3.1.18 \
		hxt-charproperties-9.4.0.0 \
		hxt-regex-xmlschema-9.2.0.3_1 \
		hxt-unicode-9.0.2.4 \
		integer-logarithms-1.0.3_2 \
		ipynb-0.1.0.1 \
		jira-wiki-markup-1.3.2 \
		libyaml-0.1.2 \
		memory-0.15.0_1 \
		mime-types-0.1.0.9 \
		mono-traversable-1.0.15.1 \
		network-3.1.1.1 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		pandoc-2.10 \
		pandoc-types-1.21 \
		pem-0.2.4 \
		primitive-0.7.1.0 \
		random-1.1_1 \
		regex-base-0.94.0.0_1 \
		regex-pcre-builtin-0.95.1.2.8.43 \
		resourcet-1.2.4.2 \
		rfc5051-0.1.0.4 \
		safe-0.3.19 \
		scientific-0.3.6.2 \
		setenv-0.1.1.3_1 \
		skylighting-0.8.5 \
		skylighting-core-0.8.5 \
		socks-0.6.1 \
		split-0.2.3.4 \
		splitmix-0.0.5 \
		streaming-commons-0.2.1.2 \
		syb-0.7.1 \
		tagged-0.8.6_2 \
		tagsoup-0.14.8 \
		temporary-1.3 \
		texmath-0.12.0.2 \
		text-conversions-0.3.0 \
		th-abstraction-0.3.2.0 \
		time-compat-1.9.3 \
		tls-1.5.4 \
		transformers-compat-0.6.5 \
		typed-process-0.2.6.0 \
		unicode-transforms-0.3.6 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.11.0 \
		utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		xml-1.3.14_2 \
		xml-conduit-1.8.0.1 \
		xml-types-0.3.7 \
		yaml-0.11.4.0 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2.1_1

CABAL_FLAGS=	-test_citeproc -debug

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/pandoc-citeproc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC} && ${COPYTREE_SHARE} locales ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chicago-author-date.csl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
