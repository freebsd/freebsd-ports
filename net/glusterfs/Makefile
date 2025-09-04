PORTNAME=	glusterfs
PORTVERSION=	8.4
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	daniel@morante.net
COMMENT=	GlusterFS distributed file system
WWW=		https://www.gluster.org

LICENSE=	GPLv2 LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING-GPLV2
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING-LGPLV3

BROKEN=		Fails to build, ld: error: version script assignment of 'global' to symbol 'client_dump' failed: symbol not defined
DEPRECATED=	Outdated and unsupported upstream, current version in tree was released in 2021 while upstream is still active and is at 10.x
EXPIRATION_DATE=2025-01-31
#BROKEN_SSL=	libressl

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libcurl.so:ftp/curl \
		liburcu-bp.so:sysutils/liburcu \
		libuuid.so:misc/libuuid

USES=		autoreconf bison compiler:c11 cpe gettext gnome libtool pkgconfig python \
		readline shebangfix sqlite ssl
CPE_VENDOR=	gluster

SHEBANG_FILES=	build-aux/pkg-version \
		events/src/glustereventsd.py events/src/peer_eventsapi.py \
		events/tools/eventsdash.py extras/ganesha/ocf/ganesha_grace \
		extras/ganesha/ocf/ganesha_mon extras/ganesha/ocf/ganesha_nfsd \
		extras/ganesha/scripts/create-export-ganesha.sh \
		extras/ganesha/scripts/dbus-send.sh \
		extras/ganesha/scripts/ganesha-ha.sh \
		extras/ganesha/scripts/generate-epoch.py \
		extras/peer_add_secret_pub.in \
		extras/hook-scripts/start/post/S29CTDBsetup.sh \
		extras/hook-scripts/start/post/S30samba-start.sh \
		extras/hook-scripts/start/post/S31ganesha-start.sh \
		extras/post-upgrade-script-for-quota.sh \
		extras/pre-upgrade-script-for-quota.sh \
		extras/snap_scheduler/gcron.py \
		extras/snap_scheduler/snap_scheduler.py \
		extras/stop-all-gluster-processes.sh \
		extras/thin-arbiter/setup-thin-arbiter.sh \
		tools/gfind_missing_files/gfid_to_path.py \
		tools/glusterfind/glusterfind.in \
		tools/glusterfind/S57glusterfind-delete-post.py \
		tools/glusterfind/src/brickfind.py \
		tools/glusterfind/src/changelog.py \
		tools/glusterfind/src/nodeagent.py

USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
USE_RC_SUBR=	glusterd
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-epoll \
		--disable-georeplication \
		--localstatedir=/var \
		--with-mountutildir=${PREFIX}/sbin \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		ac_cv_func_fallocate=no \
		ac_cv_func_fdatasync=no \
		ac_cv_func_llistxattr=no \
		ac_cv_func_malloc_stats=no \
		ac_cv_func_setfsuid=no \
		ac_cv_lib_aio_io_setup=no
CPPFLAGS+=	-I"${LOCALBASE}/include"
LDFLAGS+=	-L"${LOCALBASE}/lib" -largp
INSTALL_TARGET=	install-strip
PLIST_SUB=	GLUSTERLIBDIR="lib/${PORTNAME}" \
		PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-install:
		${LN} -nfs ${PREFIX}/libexec/glusterfs/glusterfind/S57glusterfind-delete-post.py		${STAGEDIR}/var/db/glusterd/hooks/1/delete/post/S57glusterfind-delete-post
		${LN} -nfs ../libexec/glusterfs/peer_eventsapi.py						${STAGEDIR}${PREFIX}/sbin/gluster-eventsapi
		${LN} -nfs ../libexec/glusterfs/gfevents/glustereventsd.py					${STAGEDIR}${PREFIX}/sbin/glustereventsd
		${LN} -nfs ../libexec/glusterfs/gfind_missing_files/gfind_missing_files.sh			${STAGEDIR}${PREFIX}/sbin/gfind_missing_files

.include <bsd.port.mk>
