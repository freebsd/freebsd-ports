# Created by: Willem Jan Withagen <wjw@digiware.nl>
# $FreeBSD$

PORTNAME=	ceph
DISTVERSIONPREFIX=	v
DISTVERSION=	14.2.9
PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	14

MAINTAINER=	wjw@digiware.nl
COMMENT=	Ceph delivers object, block, and file storage in a unified system

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	dual

# even though i386 will build, it is not really advised.
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	\
	bash:shells/bash \
	git:devel/git \
	gperf:devel/gperf \
	yasm:devel/yasm \
	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops \
	${LOCALBASE}/bin/ld:devel/binutils
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
	libtcmalloc.so:devel/google-perftools \
	librabbitmq.so:net/rabbitmq-c
RUN_DEPENDS=	\
	bash:shells/bash \
	flock:sysutils/flock \
	jq:textproc/jq \
	smartctl:sysutils/smartmontools \
	xml:textproc/xmlstarlet \
	${LOCALBASE}/bin/getopt:misc/getopt \
	${PYTHON_PKGNAMEPREFIX}grpcio>=0:devel/py-grpcio@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}protobuf>=0:devel/py-protobuf@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}bcrypt>=0:security/py-bcrypt@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}cherrypy>=0:www/py-cherrypy@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pecan>=0:www/py-pecan@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes@${PY_FLAVOR}

USES=		cmake:noninja dos2unix fuse gettext-runtime gmake ncurses \
		pkgconfig python:3.7+ shebangfix ssl
USE_PYTHON=	cython py3kplist
USE_OPENLDAP=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ceph:DEFAULT
DOS2UNIX_FILES=	src/pybind/mgr/diskprediction_cloud/common/__init__.py

CONFLICTS_INSTALL=	ceph
PORTSCOUT=	limit:^v14\.

GH_TUPLE+=	ceph:ceph-erasure-code-corpus:2d7d78b:ceph_erasure_code_corpus/ceph-erasure-code-corpus
GH_TUPLE+=	ceph:ceph-object-corpus:e32bf8c:ceph_object_corpus/ceph-object-corpus
GH_TUPLE+=	ceph:civetweb:bb99e93:civetweb/src/civetweb
GH_TUPLE+=	01org:isa-l_crypto:603529a:isa_l_crypto/src/crypto/isa-l/isa-l_crypto
GH_TUPLE+=	ceph:dmclock:4496dbc:dmclock/src/dmclock
GH_TUPLE+=	ceph:gf-complete:7e61b44:gf_complete/src/erasure-code/jerasure/gf-complete
GH_TUPLE+=	ceph:jerasure:96c76b8:jerasure/src/erasure-code/jerasure/jerasure
GH_TUPLE+=	ceph:googletest:fdb8504:googletest/src/googletest
GH_TUPLE+=	ceph:isa-l:7e1a337:isa_l/src/isa-l
GH_TUPLE+=	ceph:lua:1fce39c:lua/src/lua
GH_TUPLE+=	ceph:rapidjson:f54b0e4:rapidjson/src/rapidjson
GH_TUPLE+=	ceph:rocksdb:4c736f1:rocksdb/src/rocksdb
GH_TUPLE+=	ceph:xxHash:1f40c65:xxHash/src/xxHash
GH_TUPLE+=	facebook:zstd:f4340f4:zstd/src/zstd

CMAKE_BUILD_TYPE=	Release
CMAKE_ON=	WITH_SYSTEM_BOOST WITH_BOOST_CONTEXT WITH_FUSE WITH_PYTHON3
CMAKE_OFF=	WITH_LTTNG WITH_BABELTRACE WITH_KRBD WITH_XFS \
		WITH_SPDK WITH_RDMA WITH_MGR_DASHBOARD_FRONTEND WITH_PYTHON2
CMAKE_ARGS=	-D MGR_PYTHON_VERSION=${PYTHON_VER} \
		-D CEPH_MAN_DIR:STRING=man

SHEBANG_FILES=	src/rbdmap src/ceph-post-file.in src/rbd-replay-many \
		src/tools/ceph-monstore-update-crush.sh src/mount.fuse.ceph \
		src/ceph-create-keys

USE_RC_SUBR=	ceph
USE_LDCONFIG=	yes

USERS=		ceph
GROUPS=		ceph

PLIST_SUB=	CMAKE_BUILD_TYPE_regex=\bdebug\b

pre-configure:
	[ -e ${WRKSRC}/build ] || ${LN} -s ${CONFIGURE_WRKSRC} ${WRKSRC}/build
	${CP} files/file-git_version ${WRKSRC}/src/.git_version
	# Use the module finders that come with Cmake for Boost and Python
	${RM} ${WRKSRC}/cmake/modules/FindBoost.cmake || true

post-install:
	# To install a ceph.conf sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ceph
	${INSTALL_DATA} ${WRKSRC}/src/sample.ceph.conf ${STAGEDIR}${PREFIX}/etc/ceph/ceph.conf.sample
	# Get logging and rotation working
	${MKDIR} ${STAGEDIR}/var/log/ceph
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} files/file-newsyslog_ceph-log.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	# Create directories used bij daemons
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
	# For PID files and command sockets and log files
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
	${RM} ${STAGEDIR}${PREFIX}/sbin/ceph-volume-systemd
	${RM} -rf ${STAGEDIR}${PREFIX}/libexec/systemd
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/init.d

.include <bsd.port.mk>
