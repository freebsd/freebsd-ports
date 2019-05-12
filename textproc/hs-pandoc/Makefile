# Created by: John MacFarlane <jgm@berkeley.edu>
# $FreeBSD$

PORTNAME=	pandoc
PORTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USES=		cabal

OPTIONS_DEFINE=		EMBED_DATA TRYPANDOC
OPTIONS_DEFAULT=	EMBED_DATA

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_CABAL_FLAGS=	embed_data_files
EMBED_DATA_USE_CABAL=	file-embed-0.0.11

TRYPANDOC_DESC=		Build trypandoc cgi executable
TRYPANDOC_CABAL_FLAGS=	trypandoc
TRYPANDOC_USE_CABAL=	appar-0.1.7 auto-update-0.1.4 byteorder-1.0.4 \
			cabal-doctest-1.0.6_2 easy-file-0.2.2 fast-logger-2.4.13 \
			hsc2hs-0.68.4_1 iproute-1.7.7 resourcet-1.2.2 \
			semigroups-0.18.5 unix-compat-0.5.1 unix-time-0.4.5 \
			unliftio-core-0.1.2.0_1 vault-0.3.1.2 void-0.7.2 wai-3.2.2 \
			wai-extra-3.0.25 wai-logger-2.3.4 word8-0.1.3
TRYPANDOC_EXECUTABLES=	trypandoc

USE_CABAL=	Glob-0.10.0 HTTP-4000.3.12_2 HsYAML-0.1.1.3 JuicyPixels-3.3.3_1 \
		QuickCheck-2.12.6.1_1 SHA-1.6.4.4 aeson-1.4.2.0_1 \
		aeson-pretty-0.8.7 ansi-terminal-0.9 asn1-encoding-0.9.5 \
		asn1-parse-0.9.4 asn1-types-0.3.2 async-2.2.1_1 attoparsec-0.13.2.2 \
		base64-bytestring-1.0.0.2 base-compat-0.10.5 basement-0.0.10 \
		bitarray-0.0.1.1 blaze-builder-0.4.1.0 blaze-html-0.9.1.1 \
		blaze-markup-0.8.2.2 byteable-0.1.1 case-insensitive-1.2.0.11 \
		cereal-0.5.8.0 cmark-gfm-0.1.8 colour-2.3.4 connection-0.2.8 \
		cookie-0.4.4 cryptonite-0.25 data-default-0.7.1.1 \
		data-default-class-0.1.2.0 data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 digest-0.0.1.2 dlist-0.8.0.5 \
		doctemplates-0.2.2.1 erf-2.0.0.0 exceptions-0.10.0_2 fail-4.9.0.0 \
		haddock-library-1.7.0 hashable-1.2.7.0_1 hourglass-0.2.12 \
		hslua-1.0.2 hslua-module-text-0.2.0 http-client-0.6.1 \
		http-client-tls-0.3.5.3 http-types-0.12.2 hxt-9.3.1.16 \
		hxt-charproperties-9.2.0.1 hxt-regex-xmlschema-9.2.0.3 \
		hxt-unicode-9.0.2.4 integer-logarithms-1.0.2.2 ipynb-0.1 \
		memory-0.14.18 mime-types-0.1.0.9 network-2.7.0.2_2 \
		network-uri-2.6.1.0_1 old-locale-1.0.0.7_2 \
		pandoc-types-1.17.5.4 pem-0.2.4 primitive-0.6.4.0_1 random-1.1_1 \
		regex-base-0.93.2 regex-pcre-builtin-0.94.4.8.8.35 safe-0.3.17 \
		scientific-0.3.6.2 skylighting-0.7.7 skylighting-core-0.7.7 \
		socks-0.5.6 split-0.2.3.3_1 streaming-commons-0.2.1.0 syb-0.7 \
		tagged-0.8.6 tagsoup-0.14.7 temporary-1.3 texmath-0.11.2.2 \
		tf-random-0.5 th-abstraction-0.2.10.0 \
		time-locale-compat-0.1.1.5 tls-1.4.1 transformers-compat-0.6.2 \
		unicode-transforms-0.3.5 unordered-containers-0.2.10.0 \
		utf8-string-1.0.1.1_3 uuid-types-1.0.3_1 vector-0.12.0.2 \
		x509-1.7.5 x509-store-1.6.7 x509-system-1.6.6 \
		x509-validation-1.6.11 xml-1.3.14 zip-archive-0.4 zlib-0.6.2

CABAL_FLAGS=	-static derive_json_via_th

PLIST_FILES=	man/man1/pandoc.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
