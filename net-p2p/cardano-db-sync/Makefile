PORTNAME=	cardano-db-sync
PORTVERSION=	13.7.2.1
CATEGORIES=	net-p2p databases
MASTER_SITES=	https://chap.intersectmbo.org/package/:chap

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	PostgreSQL-driven Cardano blockchain data tool
WWW=		https://cardano.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	ghc-9.8.4:lang/ghc98 \
		protoc:devel/protobuf
LIB_DEPENDS=	libsecp256k1.so:math/secp256k1 \
		libblst.so:security/blst \
		libicuuc.so:devel/icu \
		liblmdb.so:databases/lmdb0 \
		libsnappy.so:archivers/snappy
RUN_DEPENDS=	cardano-node:net-p2p/cardano-node \
		bash:shells/bash \
		${LOCALBASE}/share/rc-subr-jail/rc.subr.jail:ports-mgmt/rc-subr-jail

USES=		autoreconf:build cabal gmake libtool pkgconfig pgsql:14+

WANT_PGSQL=	client server

USE_GITHUB=	yes
GH_ACCOUNT=	IntersectMBO

GH_TUPLE=	IntersectMBO:libsodium:${LIBSODIUM_HASH}:sodium	\
		IntersectMBO:cardano-node:97036a66bcf8c89f687ae57a048eecc0389977ef:cardano_node/dist-newstyle/src/cardano-n_-4abd519455c1b4f78e985afa5fc250698946913c0d932d4a5e30567de5e7b519

CARDANO_DB_SYNC_HASH=	db8cdf668cda632e9a09c30e1159fcb9fb34e952
LIBSODIUM_HASH=		dbb48cce5429cb6585c9034f002568964f1ce567

USE_RC_SUBR=		cardano_db_sync
LIBS_PREFIX=		${WRKDIR}/libs_install
BINARY_ALIAS=		git=true

CABAL_PROJECT=		append
CABAL_EXECUTABLES=	cardano-db-sync cardano-db-tool
CABAL_REPOSITORIES=	chap

WITH_LTO=		yes

post-patch:
	${REINPLACE_CMD} -e 's/$$(gitRevFromGit)/"${CARDANO_DB_SYNC_HASH}"/' \
			-e '/Cardano.Db.Git.RevFromGit/d' \
			${WRKSRC}/cardano-db/src/Cardano/Db/Git/Version.hs

pre-build:
	@${MKDIR} ${PKGCONFIG_LINKDIR}

	cd ${WRKSRC_sodium} && ./autogen.sh
	cd ${WRKSRC_sodium} && ./configure --prefix=${LIBS_PREFIX} --with-pthreads --disable-shared
	cd ${WRKSRC_sodium} && ${GMAKE} -j${MAKE_JOBS_NUMBER} && ${GMAKE} ${INSTALL_TARGET}
	${MV} ${LIBS_PREFIX}/lib/pkgconfig/libsodium.pc ${PKGCONFIG_LINKDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/postgresql-setup.sh ${STAGEDIR}${PREFIX}/bin/cardano-db-sync-pgsql-setup
	${MKDIR} ${STAGEDIR}${DATADIR}/schema
	cd ${WRKSRC}/schema && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/schema

.include <bsd.port.mk>
