# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webcamd
DISTVERSION=	5.10.6.1
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Port of Linux USB webcam and DVB drivers into userspace

LICENSE=	GPLv2

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:multimedia/v4l_compat

USES=		pkgconfig tar:bzip2 uidfix
MAKE_ARGS=	LIBDIR="${LOCALBASE}/lib" HAVE_CUSE="YES"
USE_RC_SUBR=	webcamd
SUB_FILES=	webcamd.conf

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${DISTVERSION}
GH_TUPLE=	torvalds:linux:v5.10-rc6:linux

OPTIONS_DEFINE=	DEBUG VT_CLIENT VT_SERVER DVB INPUT KEYBOARD MOUSE RADIO WEBCAM
OPTIONS_DEFAULT=DVB INPUT RADIO WEBCAM

#
# 32-bit compatibility support is mostly useful for
# platforms using 32-bit applications:
#
OPTIONS_DEFINE_amd64=		COMPAT32
OPTIONS_DEFAULT_amd64=		COMPAT32

COMPAT32_DESC=	Enable 32-bit compatibility support
COMPAT32_MAKE_ARGS=	HAVE_COMPAT32="YES"

DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

VT_CLIENT_DESC=	Build with vTuner client support
VT_CLIENT_MAKE_ARGS=	HAVE_VTUNER_CLIENT="YES"

VT_SERVER_DESC=	Build with vTuner server support
VT_SERVER_MAKE_ARGS=	HAVE_VTUNER_SERVER="YES"

DVB_DESC=	Build with USB DVB support (DVB-X, analog TV, ...)
DVB_MAKE_ARGS=		HAVE_DVB_DRV="YES"

INPUT_DESC=	Build with USB input support (tablet, joystick, HID, IR, ...)
INPUT_MAKE_ARGS=	HAVE_INPUT_DRV="YES"

KEYBOARD_DESC=	Build with USB keyboard support
KEYBOARD_MAKE_ARGS=	HAVE_KEYBOARD_DRV="YES"

MOUSE_DESC=	Build with USB mouse support
MOUSE_MAKE_ARGS=	HAVE_MOUSE_DRV="YES"

RADIO_DESC=	Build with USB radio support
RADIO_MAKE_ARGS=	HAVE_RADIO_DRV="YES"

WEBCAM_DESC=	Build with USB webcam support (UVC, gspca, ...)
WEBCAM_MAKE_ARGS=	HAVE_WEBCAM_DRV="YES"

USERS=		webcamd
GROUPS=		webcamd

MAKE_ARGS+=	HAVE_MAN="YES"
MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

WEBCAMDDIR=	${WRKDIR}/webcamd-${DISTVERSION}
LINUXDIR=	${WRKDIR}/linux-*

do-configure:
	${MAKE} -C${WEBCAMDDIR}/tools/linux_make
	${MAKE} ${MAKE_ARGS} configure -C${WEBCAMDDIR}

post-patch:
	@(${RM} -r ${WEBCAMDDIR}/media_tree && ${LN} -s ${LINUXDIR} ${WEBCAMDDIR}/media_tree)
	@(cd ${WEBCAMDDIR}/patches && ${SH} ./do_patch.sh)

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} "${WRKDIR}/webcamd.conf" ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
