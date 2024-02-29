PORTNAME=	gitit
PORTVERSION=	0.15.1.2
CATEGORIES=	www haskell

MAINTAINER=	joemann@beefree.free.de
COMMENT=	Wiki using happstack and pandoc, and git or darcs or mercurial
WWW=		https://github.com/jgm/gitit

LICENSE=	GPLv2

USES=		cabal

OPTIONS_DEFINE=		PLUGINS EXPORTS
OPTIONS_DEFAULT=	PLUGINS

# "Plugin support makes the gitit executable considerably larger
#  and more memory-hungry". (jgm)
PLUGINS_DESC=		Enable support for plugins
PLUGINS_CABAL_FLAGS=	plugins

# "This feature is a security risk; it provided multiple
#  vectors by which contents of files could be exposed". (jgm)
EXPORTS_DESC=		Enable page exports to many formats (insecure!)
# This is the commit which removed the export options:
# https://github.com/jgm/gitit/commit/eed32638f4f6e3b2f4b8a9a04c4b72001acf9ad8
# To re-enable exports in gitit we have to revert it:
# git diff --no-prefix eed3263 735096f > extra-patch-exports
EXPORTS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-exports \
		${PATCHDIR}/extra-patch-data_default.conf \
		${PATCHDIR}/extra-patch-src_Network_Gitit_Export.hs \
		${PATCHDIR}/extra-patch-src_Network_Gitit_Layout.hs \
		${PATCHDIR}/extra-patch-src_Network_Gitit_Types.hs
# Besides applying the above patches one also has to set "exports: yes"
# in a gitit instance's config file to enable exports for that instance.

USE_CABAL=	Diff-0.4.1 \
		Glob-0.10.2_3 \
		HStringTemplate-0.8.8_6 \
		HTTP-4000.4.1_3 \
		JuicyPixels-3.3.8_1 \
		OneTuple-0.4.1.1_1 \
		Only-0.1_2 \
		QuickCheck-2.14.3 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_3 \
		aeson-pretty-0.8.10 \
		alex-3.5.0.0 \
		ansi-terminal-1.1 \
		ansi-terminal-types-1.1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1_1 \
		async-2.2.5 \
		attoparsec-0.14.4_5 \
		attoparsec-aeson-2.1.0.0 \
		base-compat-0.13.1 \
		base-compat-batteries-0.13.1 \
		base-orphans-0.9.1 \
		base16-bytestring-1.0.2.0_1 \
		base64-0.4.2.4_4 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bifunctors-5.6.1_2 \
		bitvec-1.1.5.0 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.1.2_4 \
		blaze-markup-0.8.3.0_1 \
		byteorder-1.0.4 \
		cabal-doctest-1.0.9_3 \
		case-insensitive-1.2.1.0 \
		cassava-0.5.3.0_5 \
		cborg-0.2.10.0 \
		cereal-0.5.8.3 \
		citeproc-0.8.1 \
		cmdargs-0.10.22 \
		colour-2.3.6 \
		commonmark-0.2.5.1 \
		commonmark-extensions-0.2.5.3 \
		commonmark-pandoc-0.2.2.1 \
		comonad-5.0.8_2 \
		conduit-1.3.5 \
		conduit-extra-1.3.6 \
		contravariant-1.5.5 \
		cookie-0.4.6 \
		cryptohash-md5-0.11.101.0_3 \
		cryptohash-sha1-0.11.101.0_3 \
		crypton-0.34 \
		crypton-connection-0.3.2 \
		crypton-x509-1.7.6_1 \
		crypton-x509-store-1.6.9 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.12 \
		cryptonite-0.30 \
		css-text-0.1.3.0 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_5 \
		digest-0.0.2.1 \
		distributive-0.6.2.1_1 \
		djot-0.1.0.0 \
		dlist-1.0_1 \
		doclayout-0.4.0.1 \
		doctemplates-0.11 \
		emojis-0.1.3 \
		entropy-0.4.1.10_1 \
		extensible-exceptions-0.1.1.4 \
		feed-1.3.2.1_4 \
		file-embed-0.0.16.0 \
		filestore-0.6.5_1 \
		generically-0.1.1_2 \
		ghc-paths-0.1.0.12_5 \
		gridtables-0.1.0.0_1 \
		haddock-library-1.11.0_3 \
		half-0.3.1_1 \
		happstack-server-7.9.0 \
		happy-1.20.1.1 \
		hashable-1.4.3.0_1 \
		haskell-lexer-1.1.1 \
		hoauth2-2.10.0 \
		hourglass-0.2.12 \
		hsc2hs-0.68.10_1 \
		hslogger-1.3.1.0_9 \
		html-1.0.1.2 \
		http-client-0.7.16 \
		http-client-tls-0.3.6.3 \
		http-conduit-2.3.8.3 \
		http-types-0.12.4 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-logarithms-1.0.3.1_5 \
		iproute-1.7.12 \
		ipynb-0.2_1 \
		jira-wiki-markup-1.5.1_1 \
		json-0.11 \
		libyaml-0.1.2_1 \
		memory-0.18.0 \
		microlens-0.4.13.1_1 \
		mime-types-0.1.2.0 \
		monad-control-1.0.3.1 \
		mono-traversable-1.0.17.0 \
		network-3.1.4.0_1 \
		network-bsd-2.8.1.0_5 \
		network-info-0.2.1 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		ordered-containers-0.2.3 \
		pandoc-3.1.12.1 \
		pandoc-types-1.23.1_1 \
		pem-0.2.4 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		primitive-0.8.0.0_1 \
		random-1.2.1.2 \
		recaptcha-0.1.0.4 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_2 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		semigroups-0.20 \
		sendfile-0.7.11.5 \
		serialise-0.2.6.1_1 \
		skylighting-0.14.1 \
		skylighting-core-0.14.1 \
		skylighting-format-ansi-0.1 \
		skylighting-format-blaze-html-0.1.1.2 \
		skylighting-format-context-0.1.0.2 \
		skylighting-format-latex-0.1 \
		socks-0.6.1 \
		split-0.2.5 \
		splitmix-0.1.0.5 \
		streaming-commons-0.2.2.6_1 \
		strict-0.5_1 \
		syb-0.7.2.4 \
		system-filepath-0.4.14_2 \
		tagged-0.8.8 \
		tagsoup-0.14.8 \
		temporary-1.3 \
		texmath-0.12.8.6 \
		text-conversions-0.3.1.1 \
		text-short-0.1.5_3 \
		th-abstraction-0.5.0.0 \
		th-compat-0.1.4_4 \
		th-lift-0.8.4 \
		th-lift-instances-0.1.20 \
		these-1.2_1 \
		threads-0.5.1.8 \
		time-compat-1.9.6.1_6 \
		time-locale-compat-0.1.1.5 \
		tls-2.0.1 \
		toml-parser-1.3.2.0 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		typed-process-0.2.11.1 \
		typst-0.5.0.1 \
		typst-symbols-0.1.5_1 \
		unicode-collation-0.1.3.6 \
		unicode-data-0.4.0.1_2 \
		unicode-transforms-0.4.0.1_4 \
		uniplate-1.6.13_1 \
		unix-time-0.4.12 \
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.20_1 \
		uri-bytestring-0.3.3.1 \
		uri-bytestring-aeson-0.1.0.8 \
		url-2.1.3 \
		utf8-string-1.0.2 \
		uuid-1.3.15_3 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-algorithms-0.9.0.1_3 \
		vector-stream-0.1.0.1 \
		void-0.7.3 \
		witherable-0.4.2_4 \
		xml-1.3.14_2 \
		xml-conduit-1.9.1.3 \
		xml-types-0.3.8 \
		xss-sanitize-0.3.7.2_1 \
		yaml-0.11.11.2_2 \
		zip-archive-0.4.3 \
		zlib-0.6.3.0_4

# Switch off idle GC using -with_rtsopts=-I0 in gitit.cabal
CABAL_FLAGS=	with_rtsopts

CABAL_EXECUTABLES=	gitit expireGititCache
CABAL_WRAPPER_SCRIPTS=	gitit

USE_RC_SUBR=	gitit

post-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} README.markdown ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR} && \
		${FIND} data -name '*.orig' -exec ${RM} {} ";"

.include <bsd.port.mk>
