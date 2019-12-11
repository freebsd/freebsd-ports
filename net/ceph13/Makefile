# Created by: Willem Jan Withagen <wjw@digiware.nl>
# $FreeBSD$

PORTNAME=	ceph
DISTVERSIONPREFIX=	v
DISTVERSION=	13.2.6
PORTREVISION=	3
CATEGORIES=	net
PKGNAMESUFFIX=	13

MAINTAINER=	wjw@digiware.nl
COMMENT=	Ceph delivers object, block, and file storage in a unified system

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	dual

# even though i386 will build, it is not really advised.
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	\
	bash:shells/bash \
	git:devel/git \
	yasm:devel/yasm \
	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
	gperf:devel/gperf \
	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
LIB_DEPENDS=	\
	${PY_BOOST} \
	libboost_thread.so:devel/boost-libs \
	libleveldb.so:databases/leveldb \
	libnss3.so:security/nss \
	libcryptopp.so:security/cryptopp \
	liboath.so:security/oath-toolkit \
	libsnappy.so:archivers/snappy \
	libcurl.so:ftp/curl \
	libxml2.so:textproc/libxml2 \
	libexpat.so:textproc/expat2 \
	liblz4.so:archivers/liblz4 \
	libplds4.so:devel/nspr \
	libtcmalloc.so:devel/google-perftools
RUN_DEPENDS=	\
	bash:shells/bash \
	${LOCALBASE}/bin/getopt:misc/getopt \
	xml:textproc/xmlstarlet \
	jq:textproc/jq \
	flock:sysutils/flock \
	${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable@${PY_FLAVOR}

USES=		cmake:noninja fuse gettext-runtime gmake pkgconfig python:2.7 \
		shebangfix ssl
USE_PYTHON=	cython
USE_OPENLDAP=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ceph:DEFAULT

CONFLICTS_INSTALL=	ceph
PORTSCOUT=	limit:^v13\.

GH_TUPLE+=	ceph:ceph-erasure-code-corpus:2d7d78b:ceph_erasure_code_corpus/ceph-erasure-code-corpus
GH_TUPLE+=	ceph:ceph-object-corpus:e32bf8c:ceph_object_corpus/ceph-object-corpus
GH_TUPLE+=	ceph:civetweb:088b813:civetweb/src/civetweb
GH_TUPLE+=	01org:isa-l_crypto:603529a:isa_l_crypto/src/crypto/isa-l/isa-l_crypto
GH_TUPLE+=	ceph:gf-complete:7e61b44:gf_complete/src/erasure-code/jerasure/gf-complete
GH_TUPLE+=	ceph:jerasure:96c76b8:jerasure/src/erasure-code/jerasure/jerasure
GH_TUPLE+=	ceph:googletest:fdb8504:googletest/src/googletest
GH_TUPLE+=	ceph:isa-l:7e1a337:isa_l/src/isa-l
GH_TUPLE+=	ceph:lua:1fce39c:lua/src/lua
GH_TUPLE+=	ceph:rapidjson:f54b0e4:rapidjson/src/rapidjson
GH_TUPLE+=	ceph:rocksdb:f4a857d:rocksdb/src/rocksdb
GH_TUPLE+=	ceph:xxHash:1f40c65:xxHash/src/xxHash
GH_TUPLE+=	facebook:zstd:f4340f4:zstd/src/zstd

CMAKE_BUILD_TYPE=	Release
CMAKE_ARGS=	\
	-D WITH_SYSTEM_BOOST:BOOL=ON \
	-D CEPH_MAN_DIR:STRING=man \
	-D WITH_LTTNG:BOOL=OFF \
	-D WITH_BABELTRACE:BOOL=OFF \
	-D WITH_KRBD:BOOL=OFF \
	-D WITH_XFS:BOOL=OFF \
	-D WITH_KVS:BOOL=OFF \
	-D WITH_BLKID:BOOL=OFF \
	-D WITH_SPDK:BOOL=OFF \
	-D WITH_RDMA=OFF \
	-D WITH_BLUESTORE:BOOL=OFF \
	-D WITH_LIBCEPHFS:BOOL=OFF \
	-D WITH_CEPHFS:BOOL=OFF \
	-D WITH_EMBEDDED:BOOL=OFF \
	-D WITH_SYSTEM_BOOST:BOOL=ON \
	-D WITH_BOOST_CONTEXT:BOOL=OFF \
	-D WITH_FUSE:BOOL=ON \
	-D WITH_MANPAGE:BOOL=ON \
	-D WITH_RADOSGW_BEAST_FRONTEND:BOOL=OFF \
	-D WITH_MGR_DASHBOARD_FRONTEND:BOOL=OFF

SHEBANG_FILES=src/rbdmap src/ceph-post-file.in src/rbd-replay-many \
	src/tools/ceph-monstore-update-crush.sh src/mount.fuse.ceph \
	src/ceph-create-keys

USE_RC_SUBR=	ceph
USE_LDCONFIG=	yes

USERS=		ceph
GROUPS=		ceph

pre-configure:
	${LN} -s ${CONFIGURE_WRKSRC} ${WRKSRC}/build
	${CP} files/file-git_version ${WRKSRC}/src/.git_version

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ceph
	${MKDIR} ${STAGEDIR}/var/lib/ceph/bootstrap-mds
	${MKDIR} ${STAGEDIR}/var/lib/ceph/bootstrap-osd
	${MKDIR} ${STAGEDIR}/var/lib/ceph/bootstrap-rgw
	${MKDIR} ${STAGEDIR}/var/lib/ceph/bootstrap-mgr
	${MKDIR} ${STAGEDIR}/var/lib/ceph/mds
	${MKDIR} ${STAGEDIR}/var/lib/ceph/mon
	${MKDIR} ${STAGEDIR}/var/lib/ceph/osd
	${MKDIR} ${STAGEDIR}/var/lib/ceph/mgr
	${MKDIR} ${STAGEDIR}/var/lib/ceph/tmp
	${MKDIR} ${STAGEDIR}/var/lib/ceph/radosgw
	${MKDIR} ${STAGEDIR}/var/log/ceph
	${MKDIR} ${STAGEDIR}/var/run/ceph
	# Use the Ceph init.d script as the interface to regular
	# starting and stopping daemons. rc.d work is done thru
	# a separate rc.d/ceph script calling init-ceph again.
	${MV} ${STAGEDIR}${PREFIX}/etc/init.d/ceph ${STAGEDIR}${PREFIX}/bin/init-ceph
	# remove files not packaged
	${RM} ${STAGEDIR}${DOCSDIR}/sample.fetch_config
	${RM} ${STAGEDIR}${DOCSDIR}/sample.ceph.conf
	${RMDIR} ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_bench_log
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_multi_stress_watch
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_perf*
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_psim
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_scratchtoolpp
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_smalliobench*
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_test*
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_tpbench
	${RM} ${STAGEDIR}${PREFIX}/bin/ceph_xattr_bench
	${RM} ${STAGEDIR}${PREFIX}/sbin/ceph-disk-udev
	# ceph-volume does not support ZFS
	${RM} -rf ${STAGEDIR}${PYTHON_SITELIBDIR}/ceph_volume-*
	${RM} -rf ${STAGEDIR}${PYTHON_SITELIBDIR}/ceph_volume/
	${RM} ${STAGEDIR}${PREFIX}/sbin/ceph-volume
	${RM} ${STAGEDIR}${PREFIX}/man/man8/ceph-volume*
	${RM} ${STAGEDIR}${PREFIX}/sbin/ceph-volume-systemd
	${RM} -rf ${STAGEDIR}${PREFIX}/libexec/systemd

	${RMDIR} ${STAGEDIR}${PREFIX}/etc/init.d
	${INSTALL_DATA} ${WRKSRC}/src/sample.ceph.conf ${STAGEDIR}${PREFIX}/etc/ceph/ceph.conf.sample

.include <bsd.port.mk>
