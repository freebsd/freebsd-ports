PORTNAME=	bareos
DISTVERSIONPREFIX=	Release/
DISTVERSION=	21.1.8
PORTREVISION?=	0
CATEGORIES?=	sysutils
PKGNAMEPREFIX?=	#
PKGNAMESUFFIX?=	21-server

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	Backup archiving recovery open sourced (server)
WWW=		https://www.bareos.org/

LICENSE=	AGPLv3 LGPL3
LICENSE_COMB=	multi

CONFLICTS?=	bareos-server bareos20-server bareos19-server bareos18-server

LIB_DEPENDS+=	liblzo2.so:archivers/lzo2 \
		libjansson.so:devel/jansson

USES+=		cmake compiler:c++11-lang cpe localbase:ldflags  perl5 pkgconfig readline \
		shebangfix
USE_GITHUB=	yes
USE_PERL5=	run

USERS=		bareos
GROUPS=		${USERS}

PLIST_SUB+=	LIB_VERSION=${PORTVERSION}

USE_LDCONFIG=	yes
SHEBANG_LANG=	perl
SHEBANG_FILES=	${WRKSRC}/core/src/cats/make_catalog_backup.pl.in

CFLAGS+=	-Wno-error
CPPFLAGS+=	-I${LOCALBASE}/readline

OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SINGLE=		CRYPTO
OPTIONS_SINGLE_CRYPTO=	OPENSSL GNUTLS
OPTIONS_SUB=		yes
CRYPTO_DESC=		Cryptographic library
MTX_DESC=		Install mtx for control of autochanger devices
NDMP_DESC=		Enable build of NDMP support
SCSICRYPTO_DESC=	Build LTO AME crypto plugin

.if ${PKGNAMESUFFIX} == "21-server"
OPTIONS_GROUP=	BACKENDS
OPTIONS_GROUP_BACKENDS=	CEPHFS GFAPI RADOS
OPTIONS_DEFINE=		MTX PYTHON LMDB NDMP NLS SCSICRYPTO
OPTIONS_DEFAULT+=	LMDB PGSQL SCSICRYPTO
OPTIONS_SINGLE_DATABASE=	PGSQL
OPTIONS_SINGLE+=		DATABASE
BACKENDS_DESC=		Storage backends
DATABASE_DESC=		Database support
CEPHFS_DESC=	CEPHFS backend support
GFAPI_DESC=	GFAPI backend support
LMDB_DESC=	Enable faster accurate backup support
RADOS_DESC=	RADOS backend support

NDMP_CMAKE_ON=	-Dndmp=ON
NDMP_CMAKE_OFF=	-Dndmp=OFF
.endif

GNUTLS_CONFIGURE_WITH=	gnutls=${LOCALBASE}
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

OPENSSL_USES=		ssl
OPENSSL_CMAKE_ON=	-Dopenssl=ON
OPENSSL_CMAKE_OFF=	-Dopenssl=OFF

SCSICRYPTO_CMAKE_ON=	-Dscsi-crypto=ON
SCSICRYPTO_CMAKE_OFF=	-Dscsi-crypto=OFF

.if ${PKGNAMESUFFIX} == "21-client" || ${PKGNAMESUFFIX} == "21-server"  #Till end of the file
PYTHON_USES=		python
PYTHON_CMAKE_ON=	-DENABLE_PYTHON=ON
PYTHON_CMAKE_OFF=	-DENABLE_PYTHON=OFF
PYTHON_PLUGIN=		yes

.if !defined(WITH_CLIENT_ONLY)
LIB_DEPENDS+=	libbareos.so:sysutils/bareos21-client
USE_RC_SUBR?=	bareos-dir bareos-sd
.endif

.if defined(WITH_CLIENT_ONLY)
SUB_FILES+=	pkg-install.client pkg-deinstall.client pkg-message.client
.else
SUB_FILES+=	pkg-message.server
.endif

CMAKE_ARGS+=	-Dtcp-wrappers=ON \
		-Dsmartalloc=ON \
		-Dsysconfdir=${PREFIX}/etc \
		-Darchivedir=${BAREOS_DIR}/storage \
		-Dworkingdir=${BAREOS_DIR} \
		-Dconfdir=${PREFIX}/etc/bareos \
		-Dlibdir=${PREFIX}/lib \
		-Dlogdir=/var/log/bareos \
		-Dincludedir=${PREFIX}/include/bareos \
		-Dreadline=ON \
		-Ddisable-conio=ON \
		-Dbatch-insert=ON \
		-Dhave_plugins=ON \
		-Dplugindir=${PREFIX}/lib/bareos/plugins \
		-Dscriptdir=${PREFIX}/lib/bareos/scripts \
		-Dbackenddir=${PREFIX}/lib/bareos/backends \
		-Ddump_email=root@localhost \
		-Djob_email=root@localhost \
		-Ddb_name=bareos \
		-Dsbin-perm=755 \
		-Ddb_user=bareos \
		-Dbaseport=9101 \
		-Dpiddir=/var/run/bareos

.if defined(WITH_CLIENT_ONLY)
CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

CMAKE_ARGS+=	-Dfd-user=root \
		-Dfd-group=wheel \
		-Dlmdb=ON
.else
LMDB_CMAKE_ON=	-Dlmdb=ON
LMDB_CMAKE_OFF=	-Dlmdb=OFF
LMDB_CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

CMAKE_ARGS+=	-Ddir-user=${BAREOS_USER} \
		-Ddir-group=${BAREOS_GROUP} \
		-Dsd-user=${BAREOS_USER} \
		-Dsd-group=operator
.endif

# The user/group IDs below are registered, see
# http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/book.html#DADS-UID
#
BAREOS_USER?=	bareos
BAREOS_GROUP?=	${BAREOS_USER}
BAREOS_UID?=	997
BAREOS_GID?=	${BAREOS_UID}
BAREOS_DIR?=	/var/db/bareos

PLIST_SUB+=	BAREOS_DIR=${BAREOS_DIR}

SUB_LIST=	BAREOS_USER=${BAREOS_USER} \
		BAREOS_GROUP=${BAREOS_GROUP} \
		BAREOS_UID=${BAREOS_UID} \
		BAREOS_GID=${BAREOS_GID} \
		BAREOS_DIR=${BAREOS_DIR}

NLS_USES=		gettext
NLS_CMAKE_ON=		-Dnls=ON
CEPHFS_CMAKE_ON=	-Dcephfs=ON
CEPHFS_LIB_DEPENDS=	libcephfs.so:net/ceph14
GFAPI_CMAKE_ON=		-Dgfapi=ON
GFAPI_LIB_DEPENDS=	libglusterfs.so:net/glusterfs
RADOS_CMAKE_ON=		-Drados=ON -Dcephfs=ON
RADOS_LIB_DEPENDS=	librados.so:net/ceph14

# Client only or full server version
.if defined(WITH_CLIENT_ONLY)
CONFFILES=	fd
CMAKE_ARGS+=	-Dclient-only=ON

PKGDEINSTALL=	${FILESDIR}/pkg-deinstall.client
PKGINSTALL=	${FILESDIR}/pkg-install.client
.else
# Server only Options
CONFFILES=		sd dir
CMAKE_ARGS+=	-Dbuild-dird=ON \
		-Dbuild-stored=ON \
		-Dbuild_client_only=OFF
# Server default database

MTX_RUN_DEPENDS=	${LOCALBASE}/sbin/mtx:misc/mtx
MYSQL_VARS=	DBTYPE=mysql
MYSQL_SUB_LIST=		REQ_MYSQL=mysql REQ_PGSQL=""
PGSQL_CMAKE_ON=		-Dpostgresql=ON
PGSQL_USES=	pgsql
PGSQL_VARS=	DBTYPE=postgresql
PGSQL_SUB_LIST=		REQ_MYSQL="" REQ_PGSQL=postgresql
SQLITE3_VARS=	DBTYPE=sqlite3

PLIST_SUB+=		DBTYPE=${DBTYPE}

.endif

.if defined(WITH_CLIENT_ONLY)
MP1+=	bconsole.1
MP8+=	bareos-fd.8
.else
MP8+=	bareos.8 bareos-dir.8 bareos-sd.8 bcopy.8 bextract.8 bls.8 bscan.8 \
	btape.8 btraceback.8 bareos-dbcheck.8
MP1+=	bsmtp.1 bregex.1 bwild.1 bareos-tray-monitor.1
.endif

MAKE_ENV+=	MAN8="${MP8}" MAN1="${MP1}"

post-patch:
	@${REINPLACE_CMD}  '120,123d' ${WRKSRC}/CMakeLists.txt
.if ${PKGNAMESUFFIX} == "21-server"
	@${REINPLACE_CMD}  '51d' ${WRKSRC}/core/src/plugins/CMakeLists.txt
.endif
.if ${PKGNAMESUFFIX} == "21-client"
	@${REINPLACE_CMD} -e 's|-Werror -Wall|-Wall|g' ${PATCH_WRKSRC}/core/CMakeLists.txt
.endif

post-extract:
.if defined(WITH_CLIENT_ONLY)
.	if defined(PYTHON_PLUGIN)
		@${MKDIR} ${STAGEDIR}${ETCDIR}/python-ldap-conf.d/bareos-dir.d/fileset
		@${MKDIR} ${STAGEDIR}${ETCDIR}/python-ldap-conf.d/bareos-dir.d/job
.	endif
.endif
	@${MV} ${WRKSRC}/core/src/defaultconfigs/bareos-dir.d/fileset/'Windows All Drives.conf' \
		${WRKSRC}/core/src/defaultconfigs/bareos-dir.d/fileset/'WindowsAllDrives.conf'

.if !target(post-install)
post-install:
.if defined(WITH_CLIENT_ONLY)
	${MKDIR} ${STAGEDIR}${ETCDIR}/bconsole.d/
	${MV} ${STAGEDIR}${ETCDIR}/bconsole.conf ${STAGEDIR}${ETCDIR}/bconsole.d/bconsole.conf.sample
.else
	${INSTALL_SCRIPT} ${FILESDIR}/chio-bareos ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/bareos-barcodes ${STAGEDIR}${ETCDIR}/bareos-barcodes.sample
	${CHMOD} o+x ${STAGEDIR}${PREFIX}/bin/bsmtp
	${MV} ${STAGEDIR}${ETCDIR}/mtx-changer.conf ${STAGEDIR}${ETCDIR}/mtx-changer.conf.sample
.endif
	@${MKDIR} ${STAGEDIR}/var/run/bareos
.endif
.else
.include "${MASTERDIR}/Makefile.common"
.endif # -client and -server are defined

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
.endif

.include <bsd.port.mk>
