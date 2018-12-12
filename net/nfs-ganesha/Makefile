# $FreeBSD$

PORTNAME=	nfs-ganesha
DISTVERSIONPREFIX=	V
DISTVERSION=	2.7.0
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	fatih@gandi.net
COMMENT=	NFS fileserver that runs in user mode

LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	nfs-ganesha-kmod>0:net/nfs-ganesha-kmod \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject>0:devel/py-gobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

USES=		cmake compiler:c11 bison pkgconfig python:2.7
USE_RC_SUBR=	ganesha

USE_GITHUB=	yes
GH_TUPLE=	nfs-ganesha:ntirpc:v1.7.0:ganesha/src/libntirpc

CFLAGS+=	-Wno-error

CMAKE_ARGS=	-DLIB_INSTALL_DIR=${LOCALBASE}/lib -DUSE_GSS=OFF -DUSE_9P=OFF \
		-DUSE_FSAL_PROXY=OFF -DUSE_FSAL_GPFS=OFF -DUSE_FSAL_CEPH=OFF \
		-DUSE_FSAL_GLUSTER=OFF -DUSE_FSAL_RGW=OFF -DUSE_RADOS_RECOV=OFF \
		-DUSE_DBUS=ON -DUSE_ADMIN_TOOLS=ON
CMAKE_SOURCE_PATH= ${WRKSRC}/src

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/var
	@${MKDIR} ${STAGEDIR}/var/run/ganesha
	@${MV} ${STAGEDIR}${PREFIX}/etc/ganesha/ganesha.conf ${STAGEDIR}${PREFIX}/etc/ganesha/ganesha.conf.sample
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.pyc' -delete
	@${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
