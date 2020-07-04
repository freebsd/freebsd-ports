# $FreeBSD$

PORTNAME=	postgrest
PORTVERSION=	7.0.1
PORTREVISION=	1
CATEGORIES=	www databases haskell

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	PostgREST create a REST API to an existing Postgres database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		cabal pgsql

USE_CABAL=	HTTP-4000.3.14_1 \
		HUnit-1.6.0.0 \
		Only-0.1_1 \
		QuickCheck-2.14 \
		Ranged-sets-0.4.0_2 \
		StateVar-1.2 \
		adjunctions-4.4_2 \
		aeson-1.4.7.1_1 \
		aeson-pretty-0.8.8 \
		ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_1 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		auto-update-0.1.6 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		base-prelude-1.3 \
		base-unicode-symbols-0.2.4.2 \
		base64-bytestring-1.1.0.0 \
		basement-0.0.11_2 \
		bifunctors-5.5.7 \
		binary-parser-0.5.5_3 \
		bsb-http-chunked-0.0.0.4_2 \
		byteorder-1.0.4 \
		bytestring-strict-builder-0.4.5.3_1 \
		bytestring-tree-builder-0.2.7.3 \
		cabal-doctest-1.0.8_1 \
		call-stack-0.2.0 \
		case-insensitive-1.2.1.0 \
		cassava-0.5.2.0_1 \
		cereal-0.5.8.1 \
		charset-0.3.7.1_1 \
		colour-2.3.5 \
		comonad-5.0.6 \
		concise-0.1.0.1 \
		configurator-pg-0.2.3 \
		contravariant-1.5.2 \
		contravariant-extras-0.3.5.1 \
		cookie-0.4.5 \
		cryptohash-md5-0.11.100.1_5 \
		cryptohash-sha1-0.11.100.1_5 \
		cryptonite-0.26 \
		data-bword-0.1.0.1 \
		data-checked-0.3 \
		data-default-class-0.1.2.0 \
		data-dword-0.3.2 \
		data-endian-0.1.1 \
		data-serializer-0.3.4.1 \
		data-textual-0.3.0.3 \
		deferred-folds-0.9.10.1 \
		distributive-0.6.2 \
		dlist-0.8.0.8 \
		easy-file-0.2.2 \
		either-5.0.1.1_1 \
		entropy-0.4.1.6 \
		exceptions-0.10.4_1 \
		expiring-cache-map-0.0.6.1 \
		fast-logger-3.0.1 \
		foldl-1.4.6 \
		free-5.1.3 \
		generics-sop-0.5.1.0 \
		gitrev-1.3.1 \
		hashable-1.3.0.0_1 \
		hashtables-1.2.3.4 \
		haskell-src-exts-1.23.0 \
		haskell-src-meta-0.8.5_1 \
		hasql-1.4.2 \
		hasql-pool-0.5.2 \
		hasql-transaction-1.0.0.1 \
		heredoc-0.2.0.0 \
		hourglass-0.2.12 \
		http-date-0.0.8 \
		http-media-0.8.0.0_3 \
		http-types-0.12.3 \
		http2-2.0.4 \
		indexed-profunctors-0.1 \
		insert-ordered-containers-0.2.3.1 \
		integer-logarithms-1.0.3_2 \
		interpolatedstring-perl6-1.0.2 \
		invariant-0.5.3_1 \
		iproute-1.7.9_1 \
		jose-0.8.3 \
		kan-extensions-5.2 \
		lens-4.19.2 \
		lens-aeson-1.1 \
		loch-th-0.2.2 \
		math-functions-0.3.4.0_1 \
		megaparsec-8.0.0 \
		memory-0.15.0_1 \
		mime-types-0.1.0.9 \
		monad-control-1.0.2.3 \
		monad-time-0.3.1.0 \
		mtl-compat-0.2.2 \
		mwc-random-0.14.0.0 \
		network-3.1.1.1 \
		network-byte-order-0.1.5 \
		network-info-0.2.0.10_1 \
		network-ip-0.3.0.3 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		optics-core-0.3 \
		optics-extra-0.3 \
		optics-th-0.3 \
		optparse-applicative-0.15.1.0_1 \
		parallel-3.2.2.0_2 \
		parser-combinators-1.2.1 \
		parsers-0.12.10 \
		pem-0.2.4 \
		placeholders-0.1 \
		postgresql-binary-0.12.2 \
		postgresql-libpq-0.9.4.2_2 \
		primitive-0.7.0.1 \
		profunctors-5.5.2 \
		protolude-0.3.0 \
		psqueues-0.2.7.2_1 \
		quickcheck-instances-0.3.22_4 \
		random-1.1_1 \
		reflection-2.1.6 \
		regex-base-0.94.0.0_1 \
		regex-tdfa-1.3.1.0_1 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.4 \
		retry-0.8.1.2 \
		safe-0.3.18_1 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.4 \
		semigroups-0.19.1 \
		simple-sendfile-0.2.30 \
		sop-core-0.5.0.1 \
		split-0.2.3.4 \
		splitmix-0.0.4 \
		streaming-commons-0.2.1.2 \
		swagger2-2.6_1 \
		syb-0.7.1 \
		tagged-0.8.6_2 \
		template-haskell-compat-v0208-0.1.2.1 \
		text-builder-0.6.6.1 \
		text-latin1-0.3.1 \
		text-printer-0.5.0.1 \
		text-short-0.1.3_2 \
		th-abstraction-0.3.2.0 \
		th-expand-syns-0.4.6.0 \
		th-lift-0.8.1 \
		th-lift-instances-0.1.16 \
		th-orphans-0.13.10 \
		th-reify-many-0.1.9 \
		time-compat-1.9.3 \
		time-manager-0.0.0 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		type-hint-0.1 \
		unix-compat-0.5.2_1 \
		unix-time-0.4.7 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.10.0_1 \
		utf8-string-1.0.1.1_3 \
		uuid-1.3.13_3 \
		uuid-types-1.0.3_2 \
		vault-0.3.1.4 \
		vector-0.12.1.2 \
		vector-builder-0.3.8 \
		void-0.7.3 \
		wai-3.2.2.1 \
		wai-cors-0.2.7 \
		wai-extra-3.0.29.1 \
		wai-logger-2.3.6 \
		wai-middleware-static-0.8.3_1 \
		warp-3.3.11 \
		word8-0.1.3 \
		x509-1.7.5_1 \
		zlib-0.6.2.1_1 \
		\
		happy-1.19.12 \
		hsc2hs-0.68.7

POSTGREST_USER?=	postgrest
POSTGREST_GROUP?=	postgrest

USERS=		${POSTGREST_USER}
GROUPS=		${POSTGREST_GROUP}

SUB_FILES=	default.conf
SUB_LIST=	ETCDIR=${ETCDIR} \
		POSTGREST_USER=${POSTGREST_USER} \
		POSTGREST_GROUP=${POSTGREST_GROUP}

PLIST_SUB=	ETCDIR=${ETCDIR} \
		POSTGREST_USER=${POSTGREST_USER} \
		POSTGREST_GROUP=${POSTGREST_GROUP}

USE_RC_SUBR=	postgrest

SKIP_CABAL_PLIST=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/default.conf ${STAGEDIR}${ETCDIR}/default.conf.sample
	${INSTALL_PROGRAM} \
		$$(find ${WRKSRC}/dist-newstyle -name ${EXECUTABLES} -type f -perm +111) \
		${STAGEDIR}${PREFIX}/sbin/${EXECUTABLES}

.include <bsd.port.mk>
