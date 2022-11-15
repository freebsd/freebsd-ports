PORTNAME=	pandoc
PORTVERSION=	2.19.2
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats
WWW=		https://pandoc.org

LICENSE=	GPLv2

USES=		cabal

OPTIONS_DEFINE=		EMBED_DATA

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_CABAL_FLAGS=	embed_data_files

USE_CABAL=	Glob-0.10.2_3 \
		HUnit-1.6.2.0 \
		HsYAML-0.2.1.1_1 \
		JuicyPixels-3.3.8 \
		OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		aeson-2.1.1.0 \
		aeson-pretty-0.8.9_2 \
		ansi-terminal-0.11.3 \
		ansi-wl-pprint-0.6.9_3 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_3 \
		async-2.2.4_2 \
		attoparsec-0.14.4_2 \
		attoparsec-iso8601-1.1.0.0 \
		auto-update-0.1.6 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.7 \
		base16-bytestring-1.0.2.0 \
		base64-0.4.2.4_2 \
		base64-bytestring-1.2.1.0 \
		basement-0.0.15 \
		bifunctors-5.5.13 \
		bitvec-1.1.3.0 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_3 \
		boring-0.2_2 \
		bsb-http-chunked-0.0.0.4_3 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.9_2 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.3 \
		citeproc-0.8.0.2 \
		cmdargs-0.10.21 \
		colour-2.3.6 \
		commonmark-0.2.2 \
		commonmark-extensions-0.2.3.3 \
		commonmark-pandoc-0.2.1.2 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		conduit-extra-1.3.6 \
		connection-0.3.1_1 \
		constraints-0.13.4 \
		contravariant-1.5.5 \
		cookie-0.4.5 \
		cryptonite-0.30 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_3 \
		dec-0.0.5 \
		digest-0.0.1.3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		doclayout-0.4_1 \
		doctemplates-0.10.0.2_1 \
		easy-file-0.2.2 \
		emojis-0.1.2 \
		fast-logger-3.1.1 \
		file-embed-0.0.15.0 \
		generically-0.1 \
		gridtables-0.0.3.0_1 \
		haddock-library-1.11.0_1 \
		happy-1.20.0_1 \
		hashable-1.4.1.0 \
		haskell-lexer-1.1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.8_1 \
		hslua-2.2.1 \
		hslua-aeson-2.2.1 \
		hslua-classes-2.2.0 \
		hslua-core-2.2.1 \
		hslua-marshalling-2.2.1 \
		hslua-module-doclayout-1.0.4 \
		hslua-module-path-1.0.3 \
		hslua-module-system-1.0.2 \
		hslua-module-text-1.0.2 \
		hslua-module-version-1.0.3 \
		hslua-objectorientation-2.2.1 \
		hslua-packaging-2.2.1 \
		http-api-data-0.5_1 \
		http-client-0.7.13.1 \
		http-client-tls-0.3.6.1 \
		http-date-0.0.11 \
		http-media-0.8.0.0_7 \
		http-types-0.12.3 \
		http2-3.0.3 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_3 \
		iproute-1.7.12 \
		ipynb-0.2_1 \
		jira-wiki-markup-1.4.0_1 \
		libyaml-0.1.2_1 \
		lpeg-1.0.3 \
		lua-2.2.1 \
		memory-0.18.0 \
		mime-types-0.1.1.0 \
		mmorph-1.2.0_3 \
		monad-control-1.0.3.1 \
		mono-traversable-1.0.15.3 \
		network-3.1.2.7 \
		network-byte-order-0.1.6_1 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optparse-applicative-0.17.0.0 \
		pandoc-lua-marshal-0.1.7 \
		pandoc-types-1.22.2.1 \
		pem-0.2.4 \
		pretty-show-1.10 \
		primitive-0.7.4.0 \
		psqueues-0.2.7.3 \
		random-1.2.1.1 \
		recv-0.0.0 \
		resourcet-1.2.6 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.3 \
		scientific-0.3.7.0_3 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7 \
		servant-0.19.1 \
		servant-server-0.19.2 \
		simple-sendfile-0.2.30 \
		singleton-bool-0.1.6_2 \
		skylighting-0.13.1.1 \
		skylighting-core-0.13.1.1 \
		skylighting-format-ansi-0.1 \
		skylighting-format-blaze-html-0.1.1 \
		skylighting-format-latex-0.1 \
		socks-0.6.1 \
		some-1.0.4.1 \
		sop-core-0.5.0.2_1 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_1 \
		streaming-commons-0.2.2.5 \
		strict-0.4.0.1_4 \
		string-conversions-0.4.0.1 \
		syb-0.7.2.2 \
		tagged-0.8.6.1_3 \
		tagsoup-0.14.8 \
		temporary-1.3 \
		texmath-0.12.5.4 \
		text-conversions-0.3.1.1 \
		text-short-0.1.5_1 \
		th-abstraction-0.4.5.0 \
		th-compat-0.1.4 \
		th-lift-0.8.2_2 \
		th-lift-instances-0.1.20 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		time-manager-0.0.0_1 \
		tls-1.6.0 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_4 \
		typed-process-0.2.10.1 \
		unicode-collation-0.1.3.3 \
		unicode-data-0.4.0 \
		unicode-transforms-0.4.0.1_2 \
		uniplate-1.6.13_1 \
		unix-compat-0.6_1 \
		unix-time-0.4.8 \
		unliftio-0.2.23.0 \
		unliftio-core-0.2.0.1_2 \
		unordered-containers-0.2.19.1_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_3 \
		vault-0.3.1.5_2 \
		vector-0.13.0.0_1 \
		vector-algorithms-0.9.0.1_1 \
		vector-stream-0.1.0.0_1 \
		wai-3.2.3 \
		wai-app-static-3.1.7.4 \
		wai-extra-3.1.13.0_1 \
		wai-logger-2.4.0 \
		warp-3.3.23 \
		witherable-0.4.2_3 \
		word8-0.1.3 \
		x509-1.7.7 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		xml-1.3.14_2 \
		xml-conduit-1.9.1.1_2 \
		xml-types-0.3.8 \
		yaml-0.11.8.0_2 \
		zip-archive-0.4.2.2 \
		zlib-0.6.3.0

CABAL_PROJECT=		remove
CABAL_EXECUTABLES=	pandoc
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMBED_DATA}
# No need to use wrapper scripts when all data is compiled into an executable
.undef CABAL_WRAPPER_SCRIPTS
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == aarch64
# compiler goes out of memory
BUILD_ARGS+=   --disable-optimization
.endif

post-install-EMBED_DATA-off:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
