# Created by: John MacFarlane <jgm@berkeley.edu>

PORTNAME=	pandoc
PORTVERSION=	2.11.4
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USES=		cabal

OPTIONS_DEFINE=		EMBED_DATA TRYPANDOC

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_CABAL_FLAGS=	embed_data_files
EMBED_DATA_USE_CABAL=	file-embed-0.0.13.0

TRYPANDOC_DESC=		Build trypandoc cgi executable
TRYPANDOC_CABAL_FLAGS=	trypandoc
TRYPANDOC_USE_CABAL=	appar-0.1.8 auto-update-0.1.6 byteorder-1.0.4 \
			cabal-doctest-1.0.8_2 easy-file-0.2.2 fast-logger-3.0.1 \
			http2-2.0.3 iproute-1.7.9 network-byte-order-0.1.4.0 \
			old-time-1.1.0.3_2 psqueues-0.2.7.2_1 \
			semigroups-0.19.1 time-manager-0.0.0 unix-compat-0.5.2_1 \
			unix-time-0.4.7 unliftio-core-0.2.0.1_1 vault-0.3.1.4 \
			void-0.7.3 wai-3.2.2.1 wai-extra-3.0.29.1 \
			wai-logger-2.3.6 word8-0.1.3
TRYPANDOC_EXECUTABLES=	trypandoc

USE_CABAL=	Glob-0.10.1 \
		HTTP-4000.3.15_2 \
		HsYAML-0.2.1.0_1 \
		JuicyPixels-3.3.5 \
		QuickCheck-2.14.2 \
		SHA-1.6.4.4 \
		aeson-1.5.5.1 \
		aeson-pretty-0.8.8 \
		ansi-terminal-0.11 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4_1 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.4 \
		base16-bytestring-1.0.1.0 \
		base64-bytestring-1.1.0.0 \
		basement-0.0.11_2 \
		bifunctors-5.5.10 \
		blaze-builder-0.4.2.1 \
		blaze-html-0.9.1.2 \
		blaze-markup-0.8.2.7 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		citeproc-0.3.0.7 \
		colour-2.3.5 \
		commonmark-0.1.1.3 \
		commonmark-extensions-0.2.0.4 \
		commonmark-pandoc-0.2.0.1 \
		comonad-5.0.8 \
		conduit-1.3.4 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		cookie-0.4.5 \
		cryptonite-0.28 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.0 \
		digest-0.0.1.2 \
		distributive-0.6.2.1 \
		dlist-1.0 \
		doclayout-0.3 \
		doctemplates-0.9 \
		emojis-0.1 \
		errors-2.3.0 \
		file-embed-0.0.13.0 \
		haddock-library-1.9.0 \
		hashable-1.3.0.0_2 \
		hourglass-0.2.12 \
		hsc2hs-0.68.7 \
		hslua-1.3.0 \
		hslua-module-system-0.2.2.1 \
		hslua-module-text-0.3.0.1 \
		http-client-0.7.4 \
		http-client-tls-0.3.5.3_1 \
		http-types-0.12.3 \
		hxt-9.3.1.18 \
		hxt-charproperties-9.4.0.0 \
		hxt-regex-xmlschema-9.2.0.3_1 \
		hxt-unicode-9.0.2.4 \
		indexed-traversable-0.1.1 \
		integer-logarithms-1.0.3.1 \
		ipynb-0.1.0.1 \
		jira-wiki-markup-1.3.2 \
		memory-0.15.0_1 \
		mime-types-0.1.0.9 \
		mono-traversable-1.0.15.1 \
		network-3.1.2.1_1 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		pandoc-types-1.22 \
		pem-0.2.4 \
		primitive-0.7.1.0_1 \
		random-1.1_1 \
		resourcet-1.2.4.2 \
		rfc5051-0.2 \
		safe-0.3.19 \
		scientific-0.3.6.2 \
		skylighting-0.10.2 \
		skylighting-core-0.10.2 \
		socks-0.6.1 \
		split-0.2.3.4 \
		splitmix-0.1.0.3 \
		streaming-commons-0.2.2.1 \
		strict-0.4.0.1 \
		syb-0.7.2.1 \
		tagged-0.8.6.1 \
		tagsoup-0.14.8 \
		temporary-1.3 \
		texmath-0.12.1 \
		text-conversions-0.3.1 \
		th-abstraction-0.4.2.0 \
		these-1.1.1.1 \
		time-compat-1.9.5 \
		tls-1.5.4 \
		transformers-compat-0.6.6 \
		typed-process-0.2.6.0 \
		unicode-transforms-0.3.7.1 \
		uniplate-1.6.13_1 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.13.0 \
		utf8-string-1.0.2 \
		uuid-types-1.0.3_3 \
		vector-0.12.2.0 \
		vector-algorithms-0.8.0.4 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		xml-1.3.14_2 \
		xml-conduit-1.9.0.0 \
		xml-types-0.3.8 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2.2

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
