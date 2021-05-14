# Created by: John MacFarlane <jgm@berkeley.edu>

PORTNAME=	pandoc
PORTVERSION=	2.13
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USES=		cabal

OPTIONS_DEFINE=		EMBED_DATA TRYPANDOC

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_CABAL_FLAGS=	embed_data_files
EMBED_DATA_USE_CABAL=	file-embed-0.0.14.0

TRYPANDOC_DESC=		Build trypandoc cgi executable
TRYPANDOC_CABAL_FLAGS=	trypandoc
TRYPANDOC_USE_CABAL=	HUnit-1.6.2.0 auto-update-0.1.6 byteorder-1.0.4 \
			cabal-doctest-1.0.8_2 easy-file-0.2.2 fast-logger-3.0.1 \
			http2-3.0.1 http-types-0.12.3 network-byte-order-0.1.6_1 \
			network-run-0.2.4 old-time-1.1.0.3_2 psqueues-0.2.7.2_1 \
			semigroups-0.19.1 time-manager-0.0.0 \
			unix-time-0.4.7 unliftio-core-0.2.0.1_1 vault-0.3.1.5 \
			void-0.7.3 wai-3.2.3 wai-extra-3.1.6 \
			wai-logger-2.3.6 word8-0.1.3
TRYPANDOC_EXECUTABLES=	trypandoc

USE_CABAL=	Diff-0.4.0 \
		Glob-0.10.1 \
		HTTP-4000.3.16 \
		HsYAML-0.2.1.0_2 \
		JuicyPixels-3.3.5 \
		QuickCheck-2.14.2 \
		SHA-1.6.4.4 \
		aeson-1.5.6.0_1 \
		aeson-pretty-0.8.8 \
		ansi-terminal-0.11 \
		ansi-wl-pprint-0.6.9_2 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_1 \
		async-2.2.3 \
		attoparsec-0.13.2.5_1 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.4 \
		base16-bytestring-1.0.1.0 \
		base64-bytestring-1.2.0.1 \
		basement-0.0.12_1 \
		bifunctors-5.5.11 \
		blaze-builder-0.4.2.1 \
		blaze-html-0.9.1.2_1 \
		blaze-markup-0.8.2.8 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.8_2 \
		call-stack-0.3.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		citeproc-0.3.0.9 \
		clock-0.8.2 \
		colour-2.3.5 \
		commonmark-0.1.1.4 \
		commonmark-extensions-0.2.0.4 \
		commonmark-pandoc-0.2.0.1 \
		comonad-5.0.8 \
		conduit-1.3.4.1 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		cookie-0.4.5 \
		cryptonite-0.29 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.1 \
		digest-0.0.1.2 \
		distributive-0.6.2.1 \
		dlist-1.0 \
		doclayout-0.3.0.2 \
		doctemplates-0.9 \
		emojis-0.1 \
		errors-2.3.0 \
		file-embed-0.0.14.0 \
		haddock-library-1.9.0 \
		hashable-1.3.1.0 \
		hourglass-0.2.12 \
		hsc2hs-0.68.7_1 \
		hslua-1.3.0.1 \
		hslua-module-path-0.1.0.1 \
		hslua-module-system-0.2.2.1 \
		hslua-module-text-0.3.0.1 \
		http-client-0.7.8 \
		http-client-tls-0.3.5.3_1 \
		http-types-0.12.3 \
		indexed-traversable-0.1.1 \
		integer-logarithms-1.0.3.1 \
		iproute-1.7.11 \
		ipynb-0.1.0.1 \
		jira-wiki-markup-1.3.4 \
		memory-0.16.0 \
		mime-types-0.1.0.9 \
		mono-traversable-1.0.15.1 \
		network-3.1.2.1_1 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		optparse-applicative-0.16.1.0 \
		pandoc-types-1.22 \
		pem-0.2.4 \
		primitive-0.7.1.0_3 \
		random-1.2.0_5 \
		resourcet-1.2.4.2 \
		rfc5051-0.2 \
		safe-0.3.19 \
		scientific-0.3.6.2 \
		skylighting-0.10.5.1 \
		skylighting-core-0.10.5.1 \
		socks-0.6.1 \
		split-0.2.3.4_1 \
		splitmix-0.1.0.3 \
		streaming-commons-0.2.2.1 \
		strict-0.4.0.1 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_1 \
		tagsoup-0.14.8 \
		tasty-1.4.1 \
		tasty-golden-2.3.4 \
		tasty-hunit-0.10.0.3 \
		tasty-lua-0.2.3.2 \
		tasty-quickcheck-0.10.1.2 \
		temporary-1.3 \
		texmath-0.12.2 \
		text-conversions-0.3.1 \
		th-abstraction-0.4.2.0_1 \
		th-compat-0.1.2 \
		these-1.1.1.1_1 \
		time-compat-1.9.5_1 \
		tls-1.5.5 \
		transformers-compat-0.6.6 \
		typed-process-0.2.6.0 \
		unbounded-delays-0.1.1.1 \
		unicode-transforms-0.3.7.1_1 \
		uniplate-1.6.13_1 \
		unix-compat-0.5.3 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.13.0 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5 \
		vector-0.12.3.0 \
		vector-algorithms-0.8.0.4_1 \
		wcwidth-0.0.2 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		xml-1.3.14_2 \
		xml-conduit-1.9.1.1 \
		xml-types-0.3.8 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2.3

EXECUTABLES=	pandoc

OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-extract:
	${RM} ${WRKSRC}/cabal.project

post-install-EMBED_DATA-off:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
