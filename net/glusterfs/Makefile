# $FreeBSD$

PORTNAME=	glusterfs
PORTVERSION=	8.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	daniel@morante.net
COMMENT=	GlusterFS distributed file system

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	dual

BROKEN_SSL=	libressl

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libcurl.so:ftp/curl \
		liburcu-bp.so:sysutils/liburcu \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		autoreconf bison compiler:c11 gettext gnome libtool pkgconfig python \
		readline shebangfix sqlite ssl

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
USE_RC_SUBR=	glusterd
GNU_CONFIGURE=	yes
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
KMODDIR?=	/boot/modules

OPTIONS_DEFINE=	DOCS

post-install:
		${LN} -nfs ${PREFIX}/libexec/glusterfs/glusterfind/S57glusterfind-delete-post.py		${STAGEDIR}/var/db/glusterd/hooks/1/delete/post/S57glusterfind-delete-post
		${LN} -nfs ../libexec/glusterfs/peer_eventsapi.py						${STAGEDIR}${PREFIX}/sbin/gluster-eventsapi
		${LN} -nfs ../libexec/glusterfs/gfevents/glustereventsd.py					${STAGEDIR}${PREFIX}/sbin/glustereventsd
		${LN} -nfs ../libexec/glusterfs/gfind_missing_files/gfind_missing_files.sh			${STAGEDIR}${PREFIX}/sbin/gfind_missing_files

.include <bsd.port.mk>
