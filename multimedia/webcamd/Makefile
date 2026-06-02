PORTNAME=	webcamd
DISTVERSIONPREFIX=	v
DISTVERSION=	5.17.1.2
PORTREVISION=	3
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	75ec0e3c4171664a0c3798e7331c217828d84b6b.patch:-p1 \
		5e085e420fe9599a8e77e549cd116a50c753f77b.patch:-p1

MAINTAINER=	me@kuon.ch
COMMENT=	Port of Linux USB webcam and DVB drivers into userspace
WWW=		https://github.com/hselasky/webcamd

LICENSE=	GPLv2

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:multimedia/v4l_compat

USES=		pkgconfig tar:bzip2 uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	hselasky
GH_TUPLE=	torvalds:linux:v5.17-rc1:linux/media_tree \
		swills:v4l2loopback:8ab6a12:v4l2loopback/contrib/v4l2loopback
USE_RC_SUBR=	${PORTNAME}
MAKE_ARGS=	HAVE_CUSE="YES" \
		HAVE_MAN="YES" \
		LIBDIR="${LOCALBASE}/lib" \
		MANDIR=${PREFIX}/share/man/man \
		PTHREAD_LIBS="-lpthread"
SUB_FILES=	${PORTNAME}.conf

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

OPTIONS_DEFINE=		DEBUG DVB INPUT KEYBOARD MOUSE RADIO V4L2LOOPBACK \
			VT_CLIENT VT_SERVER WEBCAM
OPTIONS_DEFAULT=	DVB INPUT RADIO V4L2LOOPBACK WEBCAM
#
# 32-bit compatibility support is mostly useful for
# platforms using 32-bit applications:
#
OPTIONS_DEFINE_amd64=	COMPAT32
OPTIONS_DEFAULT_amd64=	COMPAT32

COMPAT32_DESC=		Enable 32-bit compatibility support
DVB_DESC=		Build with USB DVB support (DVB-X, analog TV, ...)
INPUT_DESC=		Build with USB input support (tablet, joystick, HID, IR, ...)
KEYBOARD_DESC=		Build with USB keyboard support
MOUSE_DESC=		Build with USB mouse support
RADIO_DESC=		Build with USB radio support
V4L2LOOPBACK_DESC=	Build with V4L2 loopback support
VT_CLIENT_DESC=		Build with vTuner client support
VT_SERVER_DESC=		Build with vTuner server support
WEBCAM_DESC=		Build with USB webcam support (UVC, gspca, ...)

COMPAT32_MAKE_ARGS=	HAVE_COMPAT32="YES"
DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"
DVB_MAKE_ARGS=		HAVE_DVB_DRV="YES"
INPUT_MAKE_ARGS=	HAVE_INPUT_DRV="YES"
KEYBOARD_MAKE_ARGS=	HAVE_KEYBOARD_DRV="YES"
MOUSE_MAKE_ARGS=	HAVE_MOUSE_DRV="YES"
RADIO_MAKE_ARGS=	HAVE_RADIO_DRV="YES"
V4L2LOOPBACK_MAKE_ARGS=	HAVE_V4L2LOOPBACK_DRV="YES"
VT_CLIENT_MAKE_ARGS=	HAVE_VTUNER_CLIENT="YES"
VT_SERVER_MAKE_ARGS=	HAVE_VTUNER_SERVER="YES"
WEBCAM_MAKE_ARGS=	HAVE_WEBCAM_DRV="YES"

post-patch:
	@(cd ${WRKSRC}/patches && ${SH} ./do_patch.sh)

do-configure:
	${MAKE} -C${WRKSRC}/tools/linux_make
	${MAKE} ${MAKE_ARGS} configure -C${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}.conf" ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
