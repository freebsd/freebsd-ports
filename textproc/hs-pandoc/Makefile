PORTNAME=	pandoc
PORTVERSION=	3.1.8
PORTREVISION=	2
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
		JuicyPixels-3.3.8 \
		OneTuple-0.4.1.1 \
		Only-0.1_2 \
		QuickCheck-2.14.3 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		aeson-pretty-0.8.10 \
		alex-3.4.0.0 \
		ansi-terminal-1.0 \
		ansi-terminal-types-0.11.5_1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1 \
		async-2.2.4_3 \
		attoparsec-0.14.4_4 \
		attoparsec-aeson-2.1.0.0 \
		auto-update-0.1.6 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		base-unicode-symbols-0.2.4.2 \
		base16-bytestring-1.0.2.0 \
		base64-0.4.2.4_3 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bifunctors-5.6.1_1 \
		bitvec-1.1.5.0 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.1.2_4 \
		blaze-markup-0.8.2.8_5 \
		boring-0.2.1 \
		bsb-http-chunked-0.0.0.4_3 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.9_3 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		cassava-0.5.3.0_4 \
		cereal-0.5.8.3 \
		citeproc-0.8.1 \
		cmdargs-0.10.22 \
		colour-2.3.6 \
		commonmark-0.2.3 \
		commonmark-extensions-0.2.3.6 \
		commonmark-pandoc-0.2.1.3 \
		comonad-5.0.8_1 \
		conduit-1.3.5 \
		conduit-extra-1.3.6 \
		constraints-0.13.4_1 \
		contravariant-1.5.5 \
		cookie-0.4.6 \
		crypton-0.33 \
		crypton-connection-0.3.1 \
		crypton-x509-1.7.6_1 \
		crypton-x509-store-1.6.9 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.12 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_4 \
		dec-0.0.5_1 \
		digest-0.0.1.7_1 \
		digits-0.3.1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		doclayout-0.4.0.1 \
		doctemplates-0.11 \
		easy-file-0.2.5 \
		emojis-0.1.3 \
		fast-logger-3.2.2 \
		file-embed-0.0.15.0 \
		foldable1-classes-compat-0.1_3 \
		generically-0.1.1_1 \
		gridtables-0.1.0.0 \
		haddock-library-1.11.0_2 \
		happy-1.20.1.1 \
		hashable-1.4.3.0 \
		haskell-lexer-1.1.1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.9 \
		hslua-2.3.0 \
		hslua-aeson-2.3.0.1 \
		hslua-classes-2.3.0 \
		hslua-cli-1.4.1 \
		hslua-core-2.3.1 \
		hslua-list-1.1.1 \
		hslua-marshalling-2.3.0 \
		hslua-module-doclayout-1.1.0 \
		hslua-module-path-1.1.0 \
		hslua-module-system-1.1.0.1 \
		hslua-module-text-1.1.0.1 \
		hslua-module-version-1.1.0 \
		hslua-module-zip-1.1.0 \
		hslua-objectorientation-2.3.0 \
		hslua-packaging-2.3.0 \
		hslua-repl-0.1.1 \
		hslua-typing-0.1.0 \
		http-api-data-0.6 \
		http-client-0.7.14 \
		http-client-tls-0.3.6.3 \
		http-date-0.0.11 \
		http-media-0.8.1.1 \
		http-types-0.12.3 \
		http2-4.1.4 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-conversion-0.1 \
		integer-logarithms-1.0.3.1_4 \
		iproute-1.7.12 \
		ipynb-0.2_1 \
		isocline-1.0.9 \
		jira-wiki-markup-1.5.1 \
		libyaml-0.1.2_1 \
		lpeg-1.0.4 \
		lua-2.3.1 \
		memory-0.18.0 \
		mime-types-0.1.1.0 \
		mmorph-1.2.0_3 \
		monad-control-1.0.3.1 \
		mono-traversable-1.0.15.3 \
		network-3.1.4.0_1 \
		network-byte-order-0.1.6_1 \
		network-uri-2.6.4.2 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optparse-applicative-0.18.1.0 \
		ordered-containers-0.2.3 \
		pandoc-3.1.8 \
		pandoc-lua-engine-0.2.1.2_1 \
		pandoc-lua-marshal-0.2.2 \
		pandoc-server-0.1.0.3 \
		pandoc-types-1.23.1 \
		pem-0.2.4 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.8.0.0_1 \
		psqueues-0.2.7.3 \
		random-1.2.1.1 \
		recv-0.1.0 \
		regex-base-0.94.0.2_2 \
		regex-tdfa-1.3.2.2_1 \
		resourcet-1.3.0 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.4 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		servant-0.20_3 \
		servant-server-0.20_2 \
		simple-sendfile-0.2.32 \
		singleton-bool-0.1.7 \
		skylighting-0.14 \
		skylighting-core-0.14 \
		skylighting-format-ansi-0.1 \
		skylighting-format-blaze-html-0.1.1.1 \
		skylighting-format-context-0.1.0.2 \
		skylighting-format-latex-0.1 \
		socks-0.6.1 \
		some-1.0.5 \
		sop-core-0.5.0.2_2 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		streaming-commons-0.2.2.6 \
		strict-0.5 \
		string-conversions-0.4.0.1_1 \
		syb-0.7.2.4 \
		tagged-0.8.8 \
		tagsoup-0.14.8 \
		temporary-1.3 \
		texmath-0.12.8.3 \
		text-conversions-0.3.1.1 \
		text-iso8601-0.1 \
		text-short-0.1.5_2 \
		th-abstraction-0.5.0.0 \
		th-compat-0.1.4_3 \
		th-lift-0.8.4 \
		th-lift-instances-0.1.20 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		time-manager-0.0.1 \
		tls-1.9.0 \
		toml-parser-1.3.0.0 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_5 \
		typed-process-0.2.11.0 \
		typst-0.3.2.0 \
		typst-symbols-0.1.4 \
		unicode-collation-0.1.3.5 \
		unicode-data-0.4.0.1_1 \
		unicode-transforms-0.4.0.1_3 \
		uniplate-1.6.13_1 \
		unix-compat-0.7 \
		unix-time-0.4.11 \
		unliftio-0.2.25.0 \
		unliftio-core-0.2.1.0_2 \
		unordered-containers-0.2.19.1_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_4 \
		vault-0.3.1.5_3 \
		vector-0.13.0.0_5 \
		vector-algorithms-0.9.0.1_2 \
		vector-stream-0.1.0.0_3 \
		wai-3.2.3 \
		wai-app-static-3.1.8 \
		wai-cors-0.2.7 \
		wai-extra-3.1.13.0_1 \
		wai-logger-2.4.0 \
		warp-3.3.29 \
		witherable-0.4.2_4 \
		word8-0.1.3 \
		xml-1.3.14_2 \
		xml-conduit-1.9.1.3 \
		xml-types-0.3.8 \
		yaml-0.11.11.2_2 \
		zip-archive-0.4.3 \
		zlib-0.6.3.0_3

CABAL_FLAGS=	lua

HACKAGE_DISTNAME=	pandoc-cli-0.1.1.1
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMBED_DATA}
# No need to use wrapper scripts when all data is compiled into an executable
.undef CABAL_WRAPPER_SCRIPTS
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-install-EMBED_DATA-off:
	cd ${CABAL_DEPSDIR}/${PORTNAME}-${PORTVERSION} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
post-install:
	${INSTALL_MAN} ${CABAL_DEPSDIR}/${PORTNAME}-${PORTVERSION}/man/pandoc.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
