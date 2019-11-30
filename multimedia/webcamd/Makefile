# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webcamd
PORTVERSION=	5.3.7.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Port of Linux USB webcam and DVB drivers into userspace

LICENSE=	GPLv2

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:multimedia/v4l_compat
LIB_DEPENDS=	libv4l1.so:multimedia/libv4l

USES=		pkgconfig tar:bzip2 uidfix
MAKE_ARGS=	LIBDIR="${LOCALBASE}/lib" HAVE_CUSE="YES"
USE_RC_SUBR=	webcamd
SUB_FILES=	webcamd.conf

OPTIONS_DEFINE=	COMPAT32 DEBUG HAL VT_CLIENT VT_SERVER DVB INPUT KEYBOARD MOUSE RADIO WEBCAM
OPTIONS_DEFAULT=DVB HAL INPUT RADIO WEBCAM

COMPAT32_DESC=	Enable 32-bit compatibility support
COMPAT32_MAKE_ARGS=	HAVE_COMPAT32="YES"

.if exists(/usr/lib32/libcuse.so)
OPTIONS_DEFAULT+=	COMPAT32
.endif

HAL_DESC=	Build with HAL and DBUS support
HAL_LIB_DEPENDS+=	libhal.so:sysutils/hal
HAL_LIB_DEPENDS+=	libdbus-1.so:devel/dbus
HAL_MAKE_ARGS=		HAVE_HAL="YES"
HAL_SUB_LIST=		LIBHAL="${LOCALBASE}/lib/libhal.so:${LOCALBASE}/lib/libdbus-1.so:"
HAL_SUB_LIST_OFF=	LIBHAL=""

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

do-configure:
	${MAKE} -C${WRKSRC}/tools/linux_make
	${MAKE} ${MAKE_ARGS} configure -C${WRKSRC}

post-patch:
	@(cd ${WRKSRC}/patches && ${SH} ./do_patch.sh)

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} "${WRKDIR}/webcamd.conf" ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
