PORTNAME=	pandoc-crossref
DISTVERSION=	0.3.18.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pandoc filter for numbering figures and tables
WWW=		https://hackage.haskell.org/package/pandoc-crossref

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_CABAL=	pandoc-cli-${PANDOC_VER}
USE_CABAL+=	Glob-0.10.2_3 \
		JuicyPixels-3.3.9 \
		OneTuple-0.4.2_1 \
		Only-0.1_2 \
		QuickCheck-2.15.0.1 \
		StateVar-1.2.2 \
		aeson-2.2.3.0_2 \
		aeson-pretty-0.8.10 \
		alex-3.5.1.0 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		attoparsec-aeson-2.2.2.0 \
		base-compat-0.14.1 \
		base-orphans-0.9.3 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bifunctors-5.6.2_1 \
		bitvec-1.1.5.0_2 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.11 \
		case-insensitive-1.2.1.0 \
		cassava-0.5.3.2 \
		cborg-0.2.10.0_1 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		citeproc-0.8.1.2 \
		cmdargs-0.10.22 \
		colour-2.3.6 \
		commonmark-0.2.6.1 \
		commonmark-extensions-0.2.5.6 \
		commonmark-pandoc-0.2.2.3 \
		comonad-5.0.9 \
		conduit-1.3.6 \
		conduit-extra-1.3.6 \
		contravariant-1.5.5 \
		cookie-0.5.0 \
		crypton-1.0.1 \
		crypton-connection-0.4.3 \
		crypton-x509-1.7.7 \
		crypton-x509-store-1.6.9 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.13 \
		data-default-0.7.1.3 \
		data-default-class-0.1.2.2 \
		data-default-instances-containers-0.1.0.3 \
		data-default-instances-dlist-0.0.1.2 \
		data-default-instances-old-locale-0.0.1.2 \
		data-fix-0.3.4_1 \
		digest-0.0.2.1 \
		distributive-0.6.2.1_1 \
		djot-0.1.2.2 \
		dlist-1.0_2 \
		doclayout-0.5 \
		doctemplates-0.11.0.1 \
		emojis-0.1.4.1 \
		file-embed-0.0.16.0 \
		generically-0.1.1_4 \
		gitrev-1.3.1 \
		gridtables-0.1.0.0_1 \
		haddock-library-1.11.0_5 \
		half-0.3.2 \
		happy-2.1.3 \
		happy-lib-2.1.3 \
		hashable-1.5.0.0_1 \
		haskell-lexer-1.1.2 \
		hourglass-0.2.12_1 \
		hsc2hs-0.68.10_3 \
		http-client-0.7.18 \
		http-client-tls-0.3.6.4 \
		http-types-0.12.4 \
		indexed-traversable-0.1.4 \
		indexed-traversable-instances-0.1.2 \
		integer-conversion-0.1.1 \
		integer-logarithms-1.0.4 \
		iproute-1.7.15 \
		ipynb-0.2_1 \
		jira-wiki-markup-1.5.1_1 \
		libyaml-0.1.4 \
		libyaml-clib-0.2.5 \
		memory-0.18.0 \
		microlens-0.4.13.1_1 \
		microlens-ghc-0.4.14.3 \
		microlens-mtl-0.2.0.3_1 \
		microlens-th-0.4.3.16 \
		mime-types-0.1.2.0 \
		mono-traversable-1.0.21.0 \
		network-3.2.7.0 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		open-browser-0.2.1.0 \
		optparse-applicative-0.18.1.0 \
		ordered-containers-0.2.4 \
		os-string-2.0.7 \
		pandoc-3.6.1 \
		pandoc-types-1.23.1_2 \
		pem-0.2.4 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0_2 \
		random-1.2.1.3 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_3 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		scientific-0.3.8.0_1 \
		semialign-1.3.1_1 \
		semigroupoids-6.0.1_1 \
		serialise-0.2.6.1_3 \
		skylighting-0.14.5 \
		skylighting-core-0.14.5 \
		skylighting-format-ansi-0.1 \
		skylighting-format-blaze-html-0.1.1.3 \
		skylighting-format-context-0.1.0.2 \
		skylighting-format-latex-0.1 \
		socks-0.6.1 \
		split-0.2.5 \
		splitmix-0.1.1 \
		streaming-commons-0.2.2.6_1 \
		strict-0.5.1_1 \
		syb-0.7.2.4 \
		tagged-0.8.9 \
		tagsoup-0.14.8 \
		tasty-1.5.2 \
		temporary-1.3 \
		texmath-0.12.8.12 \
		text-conversions-0.3.1.1 \
		text-iso8601-0.1.1_1 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0 \
		th-compat-0.1.6 \
		th-lift-0.8.6 \
		th-lift-instances-0.1.20 \
		these-1.2.1_1 \
		time-compat-1.9.7_2 \
		tls-2.1.5 \
		toml-parser-2.0.1.0_1 \
		transformers-compat-0.7.2 \
		typed-process-0.2.12.0 \
		typst-0.6.1 \
		typst-symbols-0.1.7 \
		unicode-collation-0.1.3.6_1 \
		unicode-data-0.6.0_2 \
		unicode-transforms-0.4.0.1_6 \
		uniplate-1.6.13_1 \
		unix-time-0.4.16 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_4 \
		utf8-string-1.0.2 \
		utility-ht-0.0.17.2 \
		uuid-types-1.0.6_1 \
		vector-0.13.2.0 \
		vector-algorithms-0.9.0.3 \
		vector-stream-0.1.0.1_3 \
		witherable-0.5_1 \
		xml-1.3.14_2 \
		xml-conduit-1.9.1.4 \
		xml-types-0.3.8 \
		yaml-0.11.11.2_2 \
		zip-archive-0.4.3.2_1 \
		zlib-0.7.1.0_2

CABAL_EXECUTABLES=	pandoc pandoc-crossref
SKIP_CABAL_PLIST=	yes

PLIST_FILES=	bin/pandoc-crossref \
		share/man/man1/pandoc-crossref.1.gz

PANDOC_VER=	3.6.1

post-build:
	${SETENV} pandoc_datadir=${WRKSRC}/_cabal_deps/pandoc-${PANDOC_VER} \
		$$(${FIND} ${WRKSRC}/dist-newstyle -name pandoc -type f -perm +111) -s -t man ${WRKSRC}/docs/index.md -o ${WRKSRC}/docs/pandoc-crossref.1

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/pandoc
	${INSTALL_MAN} ${WRKSRC}/docs/pandoc-crossref.1 ${STAGEDIR}${MANDIRS}/man1

.include <bsd.port.mk>
