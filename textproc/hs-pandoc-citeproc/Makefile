# $FreeBSD$

PORTNAME=	pandoc-citeproc
PORTVERSION=	0.16.2
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Supports using pandoc with citeproc

LICENSE=	BSD3CLAUSE

USES=		cabal

OPTIONS_DEFINE=		BIBUTILS EMBED_DATA UNICODE_COLLATION
OPTIONS_DEFAULT=	BIBUTILS

BIBUTILS_DESC=		Use Chris Putnam's Bibutils #'
BIBUTILS_CABAL_FLAGS=	bibutils
BIBUTILS_USE_CABAL=	hs-bibutils-6.7.0.0

EMBED_DATA_DESC=	Embed locale files into the library
EMBED_DATA_CABAL_FLAGS=	embed_data_files
EMBED_DATA_USE_CABAL=	file-embed-0.0.11

UNICODE_COLLATION_DESC=		Use bindings to the Internationl Components for Unicode libraries
UNICODE_COLLATION_CABAL_FLAGS=	unicode_collation
UNICODE_COLLATION_USE_CABAL=	text-icu-0.7.0.1
UNICODE_COLLATION_LIB_DEPENDS=	libicui18n.so:devel/icu

USE_CABAL=	Glob-0.10.0 HTTP-4000.3.12_2 HsYAML-0.1.1.3 JuicyPixels-3.3.3_1 \
		QuickCheck-2.12.6.1_1 SHA-1.6.4.4 aeson-1.4.2.0_1 \
		aeson-pretty-0.8.7 ansi-terminal-0.9 asn1-encoding-0.9.5 \
		asn1-parse-0.9.4 asn1-types-0.3.2 async-2.2.1_1 attoparsec-0.13.2.2 \
		base64-bytestring-1.0.0.2 base-compat-0.10.5 basement-0.0.10_1 \
		bitarray-0.0.1.1 blaze-builder-0.4.1.0 blaze-html-0.9.1.1 \
		blaze-markup-0.8.2.2 byteable-0.1.1 case-insensitive-1.2.0.11 \
		cereal-0.5.8.0 cmark-gfm-0.1.6 colour-2.3.4 conduit-1.3.1 \
		conduit-extra-1.3.0 connection-0.2.8 cookie-0.4.4 cryptonite-0.25 \
		data-default-0.7.1.1 data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 digest-0.0.1.2 dlist-0.8.0.5 \
		doctemplates-0.2.2.1 erf-2.0.0.0 exceptions-0.10.0_2 \
		fail-4.9.0.0 haddock-library-1.7.0 hashable-1.2.7.0_1 \
		hourglass-0.2.12 hslua-1.0.2 hslua-module-text-0.2.0 \
		http-client-0.6.1 http-client-tls-0.3.5.3 http-types-0.12.2 \
		hxt-9.3.1.16 hxt-charproperties-9.2.0.1 \
		hxt-regex-xmlschema-9.2.0.3 hxt-unicode-9.0.2.4 \
		integer-logarithms-1.0.2.2 ipynb-0.1 libyaml-0.1.1.0 \
		memory-0.14.18 mime-types-0.1.0.9 mono-traversable-1.0.11.0 \
		network-2.7.0.2_2 network-uri-2.6.1.0_1 old-locale-1.0.0.7_2 \
		pandoc-2.6 pandoc-types-1.17.5.4 pem-0.2.4 primitive-0.6.4.0_1 \
		random-1.1_1 regex-base-0.93.2 regex-pcre-builtin-0.94.4.8.8.35 \
		resourcet-1.2.2 rfc5051-0.1.0.4 safe-0.3.17 scientific-0.3.6.2 \
		setenv-0.1.1.3 skylighting-0.7.6 skylighting-core-0.7.6 \
		socks-0.5.6 split-0.2.3.3_1 streaming-commons-0.2.1.0 syb-0.7 \
		tagged-0.8.6 tagsoup-0.14.7 temporary-1.3 texmath-0.11.2 \
		tf-random-0.5 th-abstraction-0.2.10.0 time-locale-compat-0.1.1.5 \
		tls-1.4.1 transformers-compat-0.6.2 typed-process-0.2.4.0 \
		unicode-transforms-0.3.5 unliftio-core-0.1.2.0_1 \
		unordered-containers-0.2.10.0 utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_1 vector-0.12.0.2 vector-algorithms-0.8.0.1 \
		x509-1.7.5 x509-store-1.6.7 x509-system-1.6.6 \
		x509-validation-1.6.11 xml-1.3.14 xml-conduit-1.8.0.1 \
		xml-types-0.3.6 yaml-0.11.0.0 zip-archive-0.4 zlib-0.6.2

CABAL_FLAGS=	-test_citeproc -debug

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/pandoc-citeproc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC} && ${COPYTREE_SHARE} locales ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chicago-author-date.csl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
