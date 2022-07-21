PORTNAME=	pandoc
PORTVERSION=	2.18
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

BROKEN_aarch64=	Causes compiler to crash

LICENSE=	GPLv2

USES=		cabal

OPTIONS_DEFINE=		EMBED_DATA TRYPANDOC

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_CABAL_FLAGS=	embed_data_files
EMBED_DATA_USE_CABAL=	file-embed-0.0.15.0

TRYPANDOC_DESC=		Build trypandoc cgi executable
TRYPANDOC_CABAL_FLAGS=	trypandoc
TRYPANDOC_USE_CABAL=	HUnit-1.6.2.0 auto-update-0.1.6 byteorder-1.0.4 \
			call-stack-0.4.0 easy-file-0.2.2 \
			fast-logger-3.1.1 http2-3.0.3 http-types-0.12.3 \
			network-byte-order-0.1.6_1 network-run-0.2.4 \
			old-time-1.1.0.3_2 psqueues-0.2.7.3 semigroups-0.19.1 \
			time-manager-0.0.0 unix-compat-0.6 unix-time-0.4.7 \
			unliftio-core-0.2.0.1_2 vault-0.3.1.5_1 void-0.7.3 \
			wai-3.2.3 wai-extra-3.1.12.1 wai-logger-2.4.0 word8-0.1.3
TRYPANDOC_EXECUTABLES=	trypandoc

USE_CABAL=	Glob-0.10.2_3 \
		HsYAML-0.2.1.1 \
		JuicyPixels-3.3.7 \
		OneTuple-0.3.1_2 \
		QuickCheck-2.14.2 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		aeson-2.0.3.0 \
		aeson-pretty-0.8.9_1 \
		ansi-terminal-0.11.3 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_2 \
		async-2.2.4_1 \
		attoparsec-0.14.4_1 \
		base-compat-0.12.1 \
		base-compat-batteries-0.12.1_2 \
		base-orphans-0.8.6 \
		base16-bytestring-1.0.2.0 \
		base64-bytestring-1.2.1.0 \
		basement-0.0.14 \
		bifunctors-5.5.12 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_2 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.9_1 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.2_1 \
		citeproc-0.7 \
		colour-2.3.6 \
		commonmark-0.2.2 \
		commonmark-extensions-0.2.3.2 \
		commonmark-pandoc-0.2.1.2 \
		comonad-5.0.8_1 \
		conduit-1.3.4.2 \
		conduit-extra-1.3.6 \
		connection-0.3.1_1 \
		contravariant-1.5.5 \
		cookie-0.4.5 \
		cryptonite-0.30 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_2 \
		digest-0.0.1.3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		doclayout-0.4 \
		doctemplates-0.10.0.2 \
		emojis-0.1.2 \
		file-embed-0.0.15.0 \
		haddock-library-1.10.0_3 \
		happy-1.20.0_1 \
		hashable-1.4.0.2 \
		haskell-lexer-1.1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.8 \
		hslua-2.2.0_1 \
		hslua-aeson-2.2.0_1 \
		hslua-classes-2.2.0 \
		hslua-core-2.2.0 \
		hslua-marshalling-2.2.0_1 \
		hslua-module-doclayout-1.0.4 \
		hslua-module-path-1.0.2 \
		hslua-module-system-1.0.2 \
		hslua-module-text-1.0.2 \
		hslua-module-version-1.0.2 \
		hslua-objectorientation-2.2.0.1 \
		hslua-packaging-2.2.0.1 \
		http-client-0.7.11_1 \
		http-client-tls-0.3.6.1 \
		http-types-0.12.3 \
		indexed-traversable-0.1.2_1 \
		indexed-traversable-instances-0.1.1 \
		integer-logarithms-1.0.3.1_2 \
		iproute-1.7.12 \
		ipynb-0.2_1 \
		jira-wiki-markup-1.4.0_1 \
		libyaml-0.1.2 \
		lpeg-1.0.3 \
		lua-2.2.0 \
		memory-0.17.0 \
		mime-types-0.1.0.9 \
		mono-traversable-1.0.15.3 \
		network-3.1.2.7 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		pandoc-lua-marshal-0.1.6 \
		pandoc-types-1.22.2 \
		pem-0.2.4 \
		pretty-show-1.10 \
		primitive-0.7.4.0 \
		random-1.2.1.1 \
		resourcet-1.2.5 \
		safe-0.3.19 \
		scientific-0.3.7.0_2 \
		semialign-1.2.0.1_1 \
		semigroupoids-5.3.7 \
		skylighting-0.12.3.1 \
		skylighting-core-0.12.3.1 \
		socks-0.6.1 \
		split-0.2.3.4_2 \
		splitmix-0.1.0.4 \
		streaming-commons-0.2.2.4 \
		strict-0.4.0.1_4 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_2 \
		tagsoup-0.14.8 \
		temporary-1.3 \
		texmath-0.12.5.1 \
		text-conversions-0.3.1.1 \
		text-short-0.1.5 \
		th-abstraction-0.4.3.0 \
		th-compat-0.1.3_1 \
		th-lift-0.8.2_1 \
		th-lift-instances-0.1.19 \
		these-1.1.1.1_5 \
		time-compat-1.9.6.1_3 \
		tls-1.5.8 \
		transformers-compat-0.7.1_1 \
		typed-process-0.2.10.1 \
		unicode-collation-0.1.3.2 \
		unicode-data-0.3.0_1 \
		unicode-transforms-0.4.0.1 \
		uniplate-1.6.13_1 \
		unliftio-core-0.2.0.1_2 \
		unordered-containers-0.2.19.1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_2 \
		vector-0.12.3.1_2 \
		vector-algorithms-0.8.0.4_1 \
		witherable-0.4.2_2 \
		x509-1.7.7 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		xml-1.3.14_2 \
		xml-conduit-1.9.1.1_1 \
		xml-types-0.3.8 \
		yaml-0.11.8.0 \
		zip-archive-0.4.2.1 \
		zlib-0.6.3.0

CABAL_PROJECT=	remove
EXECUTABLES=	pandoc

OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-install-EMBED_DATA-off:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
