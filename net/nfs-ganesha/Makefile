# $FreeBSD$

PORTNAME=	nfs-ganesha
DISTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	fatih@gandi.net
COMMENT=	NFS fileserver that runs in user mode

LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	${KMODDIR}/getfhat.ko:net/nfs-ganesha-kmod

USES=		cmake bison kmod pkgconfig python:build
USE_RC_SUBR=	ganesha

USE_GITHUB=	yes
GH_ACCOUNT=	nfs-ganesha
GH_TAGNAME=	V2.7-rc1
CFLAGS+=	-Wno-error
GH_TUPLE=	nfs-ganesha:ntirpc:b69c2c1e353:ganesha/src/libntirpc

CMAKE_ARGS=	-DLIB_INSTALL_DIR=${LOCALBASE}/lib -DUSE_GSS=OFF -DUSE_9P=OFF \
		-DUSE_FSAL_PROXY=OFF -DUSE_FSAL_GPFS=OFF -DUSE_FSAL_CEPH=OFF \
		-DUSE_FSAL_GLUSTER=OFF -DUSE_FSAL_RGW=OFF -DUSE_RADOS_RECOV=OFF \
		-DUSE_DBUS=ON -DUSE_ADMIN_TOOLS=ON
CMAKE_SOURCE_PATH= ${WRKSRC}/src

.include <bsd.port.mk>
