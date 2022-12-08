PORTNAME=	cardano-db-sync
PORTVERSION=	13.1.0.0
CATEGORIES=	net-p2p databases

PATCH_SITES=	https://arrowd.name/:freebsd_compat
PATCHFILES=	1210_1.patch:freebsd_compat

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	PostgreSQL-driven Cardano blockchain data tool
WWW=		https://cardano.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	ghc-8.10.7:lang/ghc810
RUN_DEPENDS=	cardano-node:net-p2p/cardano-node \
		bash:shells/bash

USES=		autoreconf:build cabal gmake libtool pkgconfig pgsql:14

WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	input-output-hk

GH_TUPLE=	HeinrichApfelmus:threepenny-gui:e3bb8283fc7d2e8aa374eea29426002e8dcd67a8:threepenny_gui/dist-newstyle/src/threepenn_-92d8c1b5dcc24f1d \
		haskell-works:hw-aeson:6dc309ff4260c71d9a18c220cbae8aa1dfe2a02e:hw_aeson/dist-newstyle/src/hw-aeson-446b671374758b54 \
		input-output-hk:Win32-network:3825d3abf75f83f406c1f7161883c438dac7277d:Win32_network/dist-newstyle/src/Win32-net_-5b9448ed2f179086 \
		input-output-hk:cardano-base:0f3a867493059e650cda69e20a5cbf1ace289a57:cardano_base/dist-newstyle/src/cardano-b_-c8db9876882556ed \
		input-output-hk:cardano-config:e9de7a2cf70796f6ff26eac9f9540184ded0e4e6:cardano_config/dist-newstyle/src/cardano-c_-cddf0cd12b1de19c \
		input-output-hk:cardano-crypto:f73079303f663e028288f9f4a9e08bcca39a923e:cardano_crypto/dist-newstyle/src/cardano-c_-253fd88117badd8f \
		input-output-hk:cardano-ledger:c7c63dabdb215ebdaed8b63274965966f2bf408f:cardano_ledger/dist-newstyle/src/cardano-l_-516df916d2b8a647 \
		input-output-hk:cardano-node:950c4e222086fed5ca53564e642434ce9307b0b9:cardano_node/dist-newstyle/src/cardano-n_-156536db9a177fb0 \
		input-output-hk:cardano-prelude:bb4ed71ba8e587f672d06edf9d2e376f4b055555:cardano_prelude/dist-newstyle/src/cardano-p_-cae013aee062332a \
		input-output-hk:ekg-forward:297cd9db5074339a2fb2e5ae7d0780debb670c63:ekg_forward/dist-newstyle/src/ekg-forwa_-439c40ba89351585 \
		input-output-hk:flat:ee59880f47ab835dbd73bea0847dab7869fc20d8:flat/dist-newstyle/src/flat-9eba9ae2d4d970a \
		input-output-hk:goblins:cde90a2b27f79187ca8310b6549331e59595e7ba:goblins/dist-newstyle/src/goblins-67efee8d68d79164 \
		input-output-hk:hedgehog-extras:714ee03a5a786a05fc57ac5d2f1c2edce4660d85:hedgehog_extras/dist-newstyle/src/hedgehog-_-586c3da22a5ce29b \
		input-output-hk:io-sim:f4183f274d88d0ad15817c7052df3a6a8b40e6dc:io_sim/dist-newstyle/src/io-sim-5409b7204b6dc065 \
		input-output-hk:iohk-monitoring-framework:066f7002aac5a0efc20e49643fea45454f226caa:iohk_monitoring_framework/dist-newstyle/src/iohk-moni_-1defcf7452717dc5 \
		input-output-hk:optparse-applicative:7497a29cb998721a9068d5725d49461f2bba0e7a:optparse_applicative/dist-newstyle/src/optparse-_-3cd678a226e0281a \
		input-output-hk:ouroboros-network:cb9eba406ceb2df338d8384b35c8addfe2067201:ouroboros_network/dist-newstyle/src/ouroboros_-e51b1e265e7bb521 \
		input-output-hk:plutus:a56c96598b4b25c9e28215214d25189331087244:plutus/dist-newstyle/src/plutus-5e27fa0483bd0166 \
		input-output-hk:typed-protocols:181601bc3d9e9d21a671ce01e0b481348b3ca104:typed_protocols/dist-newstyle/src/typed-pro_-3f57698e3fbfd050 \
		vshabanov:ekg-json:00ebe7211c981686e65730b7144fbf5350462608:ekg_json/dist-newstyle/src/ekg-json-e51d7dff12d02a95

GH_TUPLE+=	input-output-hk:libsodium:${LIBSODIUM_HASH}:sodium \
		bitcoin-core:secp256k1:${SECP256K1_HASH}:secp

CARDANO_DB_SYNC_HASH=	1040fa9ec85fd75ce9f02dae2006170136793d02
LIBSODIUM_HASH=		66f017f16633f2060db25e17c170c2afa0f2a8a1
# Obtained from https://github.com/input-output-hk/cardano-node/blob/master/.github/workflows/github-page.yml#L21
SECP256K1_HASH=		ac83be33d0956faf6b7f61a60ab524ef7d6a473a

USE_RC_SUBR=		cardano_db_sync
MAKE_ENV=		PKG_CONFIG_PATH=${LIBS_PREFIX}${PREFIX}/libdata/pkgconfig/
LIBS_PREFIX=		${WRKDIR}/libs_install
BINARY_ALIAS=		git=true

USE_CABAL=	Glob-0.10.2_3 \
		HUnit-1.6.2.0 \
		ListLike-4.7.6 \
		MonadRandom-0.5.3_2 \
		OneTuple-0.3.1_3 \
		Only-0.1_1 \
		QuickCheck-2.14.2 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		Stream-0.4.7.2 \
		Unique-0.4.7.9 \
		abstract-deque-0.3 \
		abstract-par-0.3.3 \
		adjunctions-4.4_2 \
		aeson-2.0.2.0_1 \
		aeson-pretty-0.8.9_2 \
		algebraic-graphs-0.6_1 \
		ansi-terminal-0.11.1 \
		ansi-wl-pprint-0.6.9_3 \
		ap-normalize-0.1.0.1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_3 \
		async-2.2.4_2 \
		async-timer-0.1.4.1 \
		atomic-primops-0.8.4 \
		attoparsec-0.13.2.5_2 \
		attoparsec-iso8601-1.0.2.0_3 \
		auto-update-0.1.6 \
		barbies-2.0.3.1 \
		base-compat-0.11.2_1 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.6 \
		base16-0.3.1.0 \
		base16-bytestring-1.0.2.0 \
		base58-bytestring-0.1.0 \
		base64-bytestring-1.2.1.0 \
		base64-bytestring-type-1.0.1_15 \
		basement-0.0.12_2 \
		bech32-1.1.2 \
		bifunctors-5.5.11_1 \
		bimap-0.4.0_1 \
		bin-0.1_2 \
		binary-orphans-1.0.2_1 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_3 \
		bsb-http-chunked-0.0.0.4_3 \
		byteorder-1.0.4 \
		bytestring-builder-0.10.8.2.0 \
		cabal-doctest-1.0.9_2 \
		call-stack-0.4.0 \
		canonical-json-0.6.0.0_1 \
		case-insensitive-1.2.1.0 \
		cassava-0.5.2.0_9 \
		cborg-0.2.6.0_2 \
		cereal-0.5.8.2_1 \
		charset-0.3.9 \
		clock-0.8.3 \
		cmdargs-0.10.21 \
		code-page-0.2.1 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		composition-prelude-3.0.0.2 \
		concurrent-output-1.10.15 \
		conduit-1.3.4.2 \
		conduit-extra-1.3.5_1 \
		connection-0.3.1_1 \
		constraints-0.13.3 \
		constraints-extras-0.3.2.1_1 \
		contravariant-1.5.5 \
		cookie-0.4.5 \
		criterion-1.5.13.0_2 \
		criterion-measurement-0.1.3.0 \
		cryptonite-0.27_1 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_3 \
		dec-0.0.4_1 \
		dense-linear-algebra-0.1.0.0 \
		dependent-map-0.4.0.0 \
		dependent-sum-0.7.1.0_2 \
		dependent-sum-template-0.1.1.1 \
		deque-0.4.4 \
		deriving-aeson-0.2.8_1 \
		deriving-compat-0.6 \
		dictionary-sharing-0.1.0.0_3 \
		digest-0.0.1.3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		dns-3.0.4_1 \
		dom-lt-0.2.3 \
		easy-file-0.2.2 \
		either-5.0.1.1_1 \
		ekg-0.4.0.15_8 \
		ekg-core-0.1.1.7_2 \
		entropy-0.4.1.7_1 \
		erf-2.0.0.0 \
		esqueleto-3.5.3.0 \
		extra-1.7.10 \
		fast-logger-3.1.1 \
		fgl-5.7.0.3_1 \
		file-embed-0.0.15.0 \
		filelock-0.1.1.5 \
		fin-0.1.1_2 \
		fingertree-0.1.5.0 \
		fmlist-0.9.4 \
		foldl-1.4.12_5 \
		formatting-6.3.7_2 \
		foundation-0.0.26.1_1 \
		free-5.1.7_1 \
		generic-data-0.9.2.1_1 \
		generic-deriving-1.14.1 \
		generic-monoid-0.1.0.1_2 \
		generic-random-1.5.0.1 \
		generics-sop-0.5.1.2_1 \
		graphviz-2999.20.1.0_2 \
		gray-code-0.3.1 \
		groups-0.5.3 \
		half-0.3.1 \
		happy-1.20.0_1 \
		hashable-1.3.5.0_1 \
		haskell-lexer-1.1 \
		hedgehog-1.1.1_2 \
		hedgehog-quickcheck-0.1.1_4 \
		hostname-1.0 \
		hourglass-0.2.12 \
		hsc2hs-0.68.8_1 \
		hspec-2.9.4 \
		hspec-core-2.9.4 \
		hspec-discover-2.9.4 \
		hspec-expectations-0.8.2 \
		http-api-data-0.4.3_6 \
		http-client-0.7.11_1 \
		http-client-tls-0.3.6.1 \
		http-conduit-2.3.8 \
		http-date-0.0.11 \
		http-media-0.8.0.0_7 \
		http-types-0.12.3 \
		http2-3.0.3 \
		indexed-profunctors-0.1.1 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1_1 \
		insert-ordered-containers-0.2.5.1_3 \
		int-cast-0.2.0.0_4 \
		integer-logarithms-1.0.3.1_3 \
		invariant-0.5.5 \
		io-streams-1.5.2.1_3 \
		io-streams-haproxy-1.0.1.0_6 \
		iproute-1.7.12 \
		js-chart-2.9.4.1 \
		kan-extensions-5.2.3 \
		katip-0.8.7.0_2 \
		lazy-search-0.1.2.1 \
		lazysmallcheck-0.6 \
		lens-5.1_1 \
		libyaml-0.1.2_1 \
		lift-type-0.1.0.1 \
		lifted-async-0.10.2.2 \
		lifted-base-0.2.3.12 \
		list-t-1.0.5.1 \
		logict-0.7.0.3_1 \
		loop-0.3.0 \
		markov-chain-usage-model-0.0.0 \
		math-functions-0.3.4.2 \
		matrix-0.3.6.1_1 \
		megaparsec-9.2.0_2 \
		memory-0.16.0_1 \
		mersenne-random-pure64-0.2.2.0_1 \
		microlens-0.4.12.0 \
		microlens-mtl-0.2.0.1 \
		microlens-th-0.4.3.10_1 \
		microstache-1.0.2_3 \
		mime-types-0.1.0.9 \
		mmorph-1.1.5_1 \
		monad-control-1.0.3.1 \
		monad-logger-0.3.36_2 \
		monad-loops-0.4.3 \
		monad-par-0.3.5_2 \
		monad-par-extras-0.3.3 \
		mono-traversable-1.0.15.3 \
		monoidal-containers-0.6.2.0_1 \
		moo-1.2 \
		mtl-compat-0.2.2 \
		mwc-random-0.15.0.2_1 \
		network-3.1.2.7 \
		network-byte-order-0.1.6_1 \
		network-uri-2.6.4.1 \
		newtype-0.2.2.0_3 \
		nothunks-0.1.3 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optics-core-0.4 \
		optics-extra-0.4_2 \
		optics-th-0.4_1 \
		optparse-applicative-0.17.0.0 \
		optparse-generic-1.4.7_2 \
		parallel-3.2.2.0_5 \
		parser-combinators-1.3.0 \
		parsers-0.12.10_2 \
		partial-order-0.2.0.0 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.13.3.0_3 \
		persistent-documentation-0.1.0.4 \
		persistent-postgresql-2.13.4.0 \
		pipes-4.3.16_6 \
		polyparse-1.13_5 \
		postgresql-libpq-0.9.4.3_3 \
		postgresql-simple-0.6.4_8 \
		pretty-show-1.10 \
		pretty-simple-4.0.0.0 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.7.3.0_2 \
		process-extras-0.7.4 \
		profunctors-5.6.2_2 \
		prometheus-2.2.3 \
		protolude-0.3.0 \
		psqueues-0.2.7.3 \
		quickcheck-instances-0.3.27_2 \
		quickcheck-io-0.2.0 \
		quickcheck-state-machine-0.7.1 \
		quiet-0.2 \
		ral-0.1_2 \
		random-1.2.1 \
		random-shuffle-0.0.4 \
		readable-0.3.1_1 \
		recursion-schemes-5.2.2.2_1 \
		reducers-3.12.4_2 \
		reflection-2.1.6_1 \
		regex-base-0.94.0.2_1 \
		regex-posix-0.96.0.1_1 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.4.3_1 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.2 \
		scientific-0.3.7.0_3 \
		secp256k1-haskell-0.6.0 \
		selective-0.4.2 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7 \
		semigroups-0.20 \
		serialise-0.2.4.0_1 \
		servant-0.19_5 \
		servant-server-0.19_1 \
		servant-swagger-1.1.10_5 \
		setenv-0.1.1.3_1 \
		show-combinators-0.2.0.0_2 \
		silently-1.2.5.2 \
		simple-sendfile-0.2.30 \
		singleton-bool-0.1.5_3 \
		size-based-0.1.2.0_1 \
		snap-core-1.0.4.2_1 \
		snap-server-1.1.2.0_2 \
		socks-0.6.1 \
		some-1.0.2 \
		sop-core-0.5.0.2_1 \
		split-0.2.3.4_2 \
		splitmix-0.1.0.4_1 \
		statistics-0.16.0.1 \
		statistics-linreg-0.3 \
		stm-chans-3.0.0.6 \
		streaming-0.2.3.1 \
		streaming-binary-0.2.2.0 \
		streaming-bytestring-0.2.1 \
		streaming-commons-0.2.2.4 \
		strict-0.4.0.1_4 \
		strict-list-0.1.6 \
		string-conv-0.1.2 \
		string-conversions-0.4.0.1 \
		swagger2-2.8.2 \
		syb-0.7.2.1 \
		system-filepath-0.4.14_1 \
		tagged-0.8.6.1_3 \
		tasty-1.4.2.1_2 \
		tasty-expected-failure-0.12.3 \
		tasty-golden-2.3.5 \
		tasty-hedgehog-1.1.0.0_3 \
		tasty-hunit-0.10.0.3 \
		tasty-quickcheck-0.10.2 \
		tdigest-0.2.1.1_3 \
		temporary-1.3 \
		terminal-size-0.3.2.1 \
		testing-type-modifiers-0.1.0.1 \
		text-ansi-0.1.1_4 \
		text-short-0.1.5_1 \
		tf-random-0.5 \
		th-abstraction-0.4.3.0 \
		th-compat-0.1.3_1 \
		th-expand-syns-0.4.9.0 \
		th-extras-0.0.0.6 \
		th-lift-0.8.2_2 \
		th-lift-instances-0.1.19_1 \
		th-orphans-0.13.12_2 \
		th-reify-many-0.1.10 \
		th-utilities-0.2.4.3 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		time-manager-0.0.0_1 \
		time-units-1.0.0 \
		tls-1.5.7 \
		transformers-base-0.4.6 \
		transformers-compat-0.6.6 \
		transformers-except-0.1.2 \
		tree-diff-0.2.1.1_2 \
		type-equality-1_4 \
		typed-process-0.2.8.0_1 \
		typerep-map-0.5.0.0 \
		unagi-chan-0.4.1.4 \
		unbounded-delays-0.1.1.1 \
		unix-bytestring-0.3.7.6 \
		unix-compat-0.5.4_2 \
		unix-time-0.4.7 \
		unliftio-0.2.21.0 \
		unliftio-core-0.2.0.1_2 \
		unordered-containers-0.2.16.0 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_3 \
		validation-selective-0.1.0.1 \
		vault-0.3.1.5_2 \
		vector-0.12.3.1_2 \
		vector-algorithms-0.8.0.4_2 \
		vector-binary-instances-0.2.5.2_3 \
		vector-th-unbox-0.2.2_3 \
		void-0.7.3 \
		wai-3.2.3 \
		wai-app-static-3.1.7.2_1 \
		wai-extra-3.1.8_1 \
		wai-logger-2.4.0 \
		warp-3.3.19 \
		wcwidth-0.0.2 \
		websockets-0.12.7.3_1 \
		websockets-snap-0.10.3.1_1 \
		wide-word-0.1.1.2_4 \
		witherable-0.4.2_3 \
		wl-pprint-annotated-0.1.0.1_1 \
		wl-pprint-text-1.2.0.2 \
		word8-0.1.3 \
		x509-1.7.6 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		yaml-0.11.7.0 \
		zlib-0.6.2.3_1 \
		zlib-bindings-0.1.1.5_2

CABAL_PROJECT=		append
CABAL_EXECUTABLES=	cardano-db-sync cardano-db-tool

post-patch:
	${REINPLACE_CMD} -e 's/$$(gitRevFromGit)/"${CARDANO_DB_SYNC_HASH}"/' \
			-e '/Cardano.Db.RevFromGit/d' \
			${WRKSRC}/cardano-db/src/Cardano/Db/Version.hs

	${ECHO_CMD} "package *" >> ${WRKSRC}/cabal.project.local
	${ECHO_CMD} "  extra-include-dirs: ${LIBS_PREFIX}${PREFIX}/include" >> ${WRKSRC}/cabal.project.local
	${ECHO_CMD} "  extra-lib-dirs: ${LIBS_PREFIX}${PREFIX}/lib" >> ${WRKSRC}/cabal.project.local

pre-build:
	cd ${WRKSRC_sodium} && ./autogen.sh
	cd ${WRKSRC_sodium} && ./configure --prefix=${PREFIX} --with-pthreads --disable-shared
	cd ${WRKSRC_sodium} && ${GMAKE} -j${MAKE_JOBS_NUMBER} && ${GMAKE} DESTDIR=${LIBS_PREFIX} ${INSTALL_TARGET}
	${MKDIR} ${LIBS_PREFIX}${PREFIX}/libdata/pkgconfig
	${MV} ${LIBS_PREFIX}${PREFIX}/lib/pkgconfig/libsodium.pc ${LIBS_PREFIX}${PREFIX}/libdata/pkgconfig/libsodium.pc

	cd ${WRKSRC_secp} && ./autogen.sh
	cd ${WRKSRC_secp} && ./configure --prefix=${PREFIX} --enable-module-schnorrsig --enable-experimental --with-pic --disable-shared
	cd ${WRKSRC_secp} && ${GMAKE} -j${MAKE_JOBS_NUMBER} && ${GMAKE} DESTDIR=${LIBS_PREFIX} ${INSTALL_TARGET}
	${MV} ${LIBS_PREFIX}${PREFIX}/lib/pkgconfig/libsecp256k1.pc ${LIBS_PREFIX}${PREFIX}/libdata/pkgconfig/libsecp256k1.pc

post-install:
	${MV} ${WRKSRC}/scripts/postgresql-setup.sh ${WRKSRC}/scripts/cardano-db-sync-pgsql-setup
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/cardano-db-sync-pgsql-setup ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/schema
	cd ${WRKSRC}/schema && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/schema

.include <bsd.port.mk>
