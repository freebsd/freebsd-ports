# $FreeBSD$

PORTNAME=	glusterfs
PORTVERSION=	3.11.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	craig001@lerwick.hopto.org
COMMENT=	GlusterFS distributed file system

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libargp.so:devel/argp-standalone liburcu-bp.so:sysutils/liburcu

USES=		bison gettext libtool pkgconfig python readline shebangfix \
		sqlite ssl

BROKEN_SSL=	libressl

SHEBANG_FILES=	extras/peer_add_secret_pub.in \
		events/src/glustereventsd.py \
		events/src/peer_eventsapi.py \
		tools/glusterfind/src/nodeagent.py \
		tools/glusterfind/src/brickfind.py \
		tools/glusterfind/src/changelog.py \
		tools/glusterfind/glusterfind.in \
		tools/gfind_missing_files/gfid_to_path.py \
		extras/pre-upgrade-script-for-quota.sh \
		events/tools/eventsdash.py \
		extras/post-upgrade-script-for-quota.sh \
		extras/snap_scheduler/gcron.py \
		extras/snap_scheduler/snap_scheduler.py \
		events/src/peer_eventsapi.py \
		events/src/glustereventsd.py \
		tools/glusterfind/S57glusterfind-delete-post.py

USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	glusterd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--with-mountutildir=${PREFIX}/sbin \
		--localstatedir=/var \
		--disable-epoll \
		--enable-glupy \
		--disable-georeplication \
		ac_cv_lib_aio_io_setup=no ac_cv_func_fallocate=no \
		ac_cv_func_setfsuid=no 	ac_cv_func_fdatasync=no \
		ac_cv_func_llistxattr=no ac_cv_func_malloc_stats=no
CPPFLAGS+=	-I"${LOCALBASE}/include"
LDFLAGS+=	-L"${LOCALBASE}/lib" -largp
INSTALL_TARGET=	install-strip
PLIST_SUB=	GLUSTERLIBDIR="lib/${PORTNAME}/${PORTVERSION}"
KMODDIR?=	/boot/modules

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1101001
USE_GCC=	yes
.endif

.include <bsd.port.mk>
