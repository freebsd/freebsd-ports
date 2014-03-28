# Created by: Dominic Fandrey <kamikaze@bsdforen.de>
# $FreeBSD$

PORTNAME=	input-wacom
PORTVERSION=	${KLD_VERSION}.${WACOM_VERSION:C/-/./g}
PORTREVISION=	3
CATEGORIES=	x11-drivers kld
MASTER_SITES=	http://www.chillt.de/bsdwacom/:bsdwacom \
		SF/linuxwacom/xf86-input-wacom/:linuxwacom
DISTFILES=	${BSDWACOM}.tbz:bsdwacom \
		${LINUXWACOM}.tar.bz2:linuxwacom

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X.Org Wacom tablet driver and kernel module

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat

MAN4=		wacom.4x
MAN1=		xsetwacom.1
#MANCOMPRESSED=	yes

USES=		gmake
USE_RC_SUBR=	wacom

KMODDIR?=	/boot/modules
XINPUTMODDIR=	lib/xorg/modules/input
MAN1DIR=	man/man1
MAN4DIR=	man/man4
WRKSRC=		${WRKDIR}

PLIST_SUB+=	KMODDIR=${KMODDIR} \
		XINPUTMODDIR=${XINPUTMODDIR} \
		PORTTYPE=${PORTTYPE}
SUB_LIST:=	${PLIST_SUB}
SUB_FILES+=	pkg-message-${PORTTYPE}
PKGMESSAGE=	${WRKDIR}/pkg-message-${PORTTYPE}

XORG_CAT=	driver
USE_XORG=	xi xrandr

LINUXWACOM=	xf86-input-wacom-${WACOM_VERSION}
BSDWACOM=	bsdwacom-${KLD_VERSION}
WACOM_VERSION=	0.15.0
KLD_VERSION=	40
PATCH_WRKSRC=	${WRKDIR}/${LINUXWACOM}
CONFIGURE_WRKSRC=	${WRKDIR}/${LINUXWACOM}
USE_AUTOTOOLS=	autoconf
MAKE_ARGS+=	UDEV_CFLAGS=""

OPTIONS_DEFINE=	UWACOMKLD
UWACOMKLD_DESC=	Install USB kernel module (not supported on 8.x)

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUWACOMKLD}
PLIST_SUB+=	UWACOMKLD="uwacom.ko"
PORTTYPE=	usb
.else
PLIST_SUB+=	UWACOMKLD="@noinst UWACOMKLD uwacom.ko"
PORTTYPE=	serial
.endif

do-build:
.if ${PORT_OPTIONS:MUWACOMKLD}
	@cd ${WRKDIR}/uwacom \
		&& ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS}
.endif
	@cd ${WRKDIR}/${LINUXWACOM} \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS}

do-install:
.if ${PORT_OPTIONS:MUWACOMKLD}
	@${MKDIR} ${KMODDIR}
	@${INSTALL_KLD} ${WRKDIR}/uwacom/uwacom.ko ${KMODDIR}/
.endif
	@${MKDIR} ${PREFIX}/${XINPUTMODDIR} ${PREFIX}/${MAN4DIR}
	@cd ${WRKDIR}/${LINUXWACOM}/tools/ \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL}
	@${INSTALL} ${WRKDIR}/${LINUXWACOM}/src/.libs/wacom_drv.so \
		${PREFIX}/${XINPUTMODDIR}/
	@${INSTALL_MAN} ${WRKDIR}/${LINUXWACOM}/man/wacom.4x \
		${PREFIX}/${MAN4DIR}/
	@${INSTALL_MAN} ${WRKDIR}/${LINUXWACOM}/man/xsetwacom.1 \
		${PREFIX}/${MAN1DIR}/

plist: clean configure
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
	@cd ${WRKDIR}/linuxwacom \
		&& ${SETENV} ${MAKE_ENV} PREFIX=${WRKDIR}/plist ./run_configure
	@${MKDIR} ${WRKDIR}/plist
	@cd ${WRKDIR}/linuxwacom/${LINUXWACOM}/src/util \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL}
	@cd ${WRKDIR}/linuxwacom \
		&& ${SETENV} ${MAKE_ENV} ./run_configure
	@${FIND} ${WRKDIR}/plist/ -not -type d \
		| ${SED} "s|${WRKDIR}/plist/||1" \
		>> ${PLIST}
	@${FIND} -d ${WRKDIR}/plist/ -mindepth 2 -type d \
		| ${SED} "s|${WRKDIR}/plist/|@dirrm |1" \
		>> ${PLIST}
	@${ECHO} "%%XINPUTMODDIR%%/wacom_drv.so" >> ${PLIST}
	@${ECHO} "@dirrmtry %%XINPUTMODDIR%%" >> ${PLIST}
	@${ECHO} "@cwd %%KMODDIR%%" >> ${PLIST}
	@${ECHO} "%%UWACOMKLD%%" >> ${PLIST}

post-install:
	@${ECHO} "===>  Displaying pkg-message."
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
