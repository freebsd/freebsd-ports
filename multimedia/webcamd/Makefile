# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webcamd
PORTVERSION=	3.11.0.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	A port of Linux USB webcam and DVB drivers into userspace

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat \
		cuse4bsd-kmod>=0.1.24:${PORTSDIR}/multimedia/cuse4bsd-kmod
LIB_DEPENDS=	v4l1.0:${PORTSDIR}/multimedia/libv4l \
		cuse4bsd.1:${PORTSDIR}/multimedia/cuse4bsd-kmod

LICENSE=	GPLv2

USE_RC_SUBR=	webcamd
USE_BZIP2=	yes
USE_LDCONFIG=	yes
MANCOMPRESSED=	yes
MAN4=		a800.4 ce6230.4 dtv5100.4 gl861.4 mr800.4 pwcusb.4 sq905c.4 \
		usbvision.4 af9005.4 cinergy.4 dw2102.4 gp8psk.4 \
		mr97310a.4 s2255.4 stk014.4 uvc.4 af9015.4 conex.4 \
		ec168.4 hdpvr.4 nova-t.4 se401.4 stv06xx.4 vc032x.4 \
		anysee.4 cpiax.4 em28xx.4 ibmcam.4 opera.4 siano.4 \
		sunplus.4 vp702x.4 au0828.4 cxusb.4 et61x251.4 \
		jeilinj.4 ov519.4 sn9c102.4 t613.4 vp7045.4 au6610.4 \
		dib0700.4 finepix.4 m5602.4 ov534.4 sn9c20x.4 ttusb2.4 \
		zc3xx.4 b2c2.4 digitv.4 friio.4 m920x.4 pacxxx.4 \
		sonixj.4 tv8532.4 zr364xx.4 benq.4 dtt200u.4 gl860.4 \
		mars.4 pvrusb2.4 spca5xx.4 umt.4
MAN8=		webcamd.8

LIBDIR=		${PREFIX}/lib

OPTIONS_DEFINE=	DEBUG HAL VT_CLIENT VT_SERVER DVB INPUT RADIO WEBCAM
OPTIONS_DEFAULT=DVB HAL INPUT RADIO WEBCAM
HAL_DESC=	Build with HAL and DBUS support
DEBUG_DESC=	Build with debugging support
VT_CLIENT_DESC=	Build with vTuner client support
VT_SERVER_DESC=	Build with vTuner server support

DVB_DESC=	Build with USB DVB support (DVB-X, analog TV, ...)
INPUT_DESC=	Build with USB input support (tablet, joystick, IR, ...)
RADIO_DESC=	Build with USB radio support
WEBCAM_DESC=	Build with USB webcam support (UVC, gspca, ...)

USERS=		webcamd
GROUPS=		webcamd

.include <bsd.port.pre.mk>

LIBCUSE=${LIBDIR}/libcuse4bsd.so

MAKE_ARGS+=" HAVE_MAN=YES"
MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.if ${PORT_OPTIONS:MDVB}
MAKE_ARGS+=" HAVE_DVB_DRV=YES"
.endif

.if ${PORT_OPTIONS:MINPUT}
MAKE_ARGS+=" HAVE_INPUT_DRV=YES"
.endif

.if ${PORT_OPTIONS:MRADIO}
MAKE_ARGS+=" HAVE_RADIO_DRV=YES"
.endif

.if ${PORT_OPTIONS:MWEBCAM}
MAKE_ARGS+=" HAVE_WEBCAM_DRV=YES"
.endif

.if ${PORT_OPTIONS:MHAL}
MAKE_ARGS+=" HAVE_HAL=YES"
LIBHAL=${LIBDIR}/libhal.so:${LIBDIR}/libdbus-1.so:
LIB_DEPENDS+=hal.1:${PORTSDIR}/sysutils/hal
LIB_DEPENDS+=dbus-1:${PORTSDIR}/devel/dbus
.else
LIBHAL=
.endif

.if ${PORT_OPTIONS:MVT_CLIENT}
MAKE_ARGS+=" HAVE_VTUNER_CLIENT=YES"
.endif

.if ${PORT_OPTIONS:MVT_SERVER}
MAKE_ARGS+=" HAVE_VTUNER_SERVER=YES"
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

#
# This step is optional
#
do-configure:
	${MAKE} -C${WRKSRC}/tools/linux_make
	${MAKE} ${MAKE_ARGS} configure -C${WRKSRC}

post-patch:
	@cd ${WRKSRC}/patches; ${SH} ./do_patch.sh

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LIBHAL%%|${LIBHAL}|g" \
		-e "s|%%LIBCUSE%%|${LIBCUSE}|g" \
		< ${FILESDIR}/webcamd.conf.in > ${WRKDIR}/webcamd.conf
	${INSTALL_DATA} "${WRKDIR}/webcamd.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
