# New ports collection makefile for:	input-wacom
# Date Created:				24 Oct 2008
# Whom:					Dominic Fandrey <kamikaze@bsdforen.de>
#
# $FreeBSD$
#

PORTNAME=	input-wacom
PORTVERSION=	${KLD_VERSION}.${WACOM_VERSION:C/-/./g}
PORTREVISION=	6
CATEGORIES=	x11-drivers kld
MASTER_SITES=	http://www.chillt.de/bsdwacom/:bsdwacom \
		SF/linuxwacom/linuxwacom/${WACOM_VERSION}:linuxwacom
DISTFILES=	${BSDWACOM}.tbz:bsdwacom \
		${LINUXWACOM}.tar.bz2:linuxwacom

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	X.Org Wacom tablet driver and kernel module

MAN4=		wacom.4x
MANCOMPRESSED=	yes

USE_GMAKE=	yes
USE_RC_SUBR=	wacom
USE_LDCONFIG=	no

KMODDIR?=	/boot/modules
XINPUTMODDIR=	lib/xorg/modules/input
MAN4DIR=	man/man4
WRKSRC=		${WRKDIR}

PLIST_SUB+=	KMODDIR=${KMODDIR} \
		XINPUTMODDIR=${XINPUTMODDIR} \
		PORTTYPE=${PORTTYPE}
SUB_LIST:=	${PLIST_SUB}
SUB_FILES+=	pkg-message-${PORTTYPE}
PKGMESSAGE=	${WRKDIR}/pkg-message-${PORTTYPE}

XORG_CAT=	driver
USE_XORG=	xi

LINUXWACOM=	linuxwacom-${WACOM_VERSION}
BSDWACOM=	bsdwacom-${KLD_VERSION}
WACOM_VERSION=	0.8.2-2
KLD_VERSION=	40

OPTIONS=	UWACOMKLD "Install USB kernel module (ignored on 8.x)" ${KMOD_SUPPORTED}

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 800064
KMOD_SUPPORTED=	Off
.undef WITH_UWACOMKLD
.else
KMOD_SUPPORTED=	On
.endif

.if defined(WITH_UWACOMKLD)
PLIST_SUB+=	UWACOMKLD="uwacom.ko"
PORTTYPE=	usb
.else
PLIST_SUB+=	UWACOMKLD="@noinst UWACOMKLD uwacom.ko"
PORTTYPE=	serial
.endif

post-patch:
	@${LN} -s ../${LINUXWACOM} ${WRKDIR}/linuxwacom/

do-configure:
	@cd ${WRKDIR}/linuxwacom && ${SETENV} ${MAKE_ENV} ./run_configure

do-build:
.if defined(WITH_UWACOMKLD)
	@cd ${WRKDIR}/uwacom \
		&& ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS}
.endif
	@cd ${WRKDIR}/${LINUXWACOM} \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS}

do-install:
.if defined(WITH_UWACOMKLD)
	@${MKDIR} ${KMODDIR}
	@${INSTALL_KLD} ${WRKDIR}/uwacom/uwacom.ko ${KMODDIR}/
.endif
	@${MKDIR} ${PREFIX}/${XINPUTMODDIR} ${PREFIX}/${MAN4DIR}
	@cd ${WRKDIR}/linuxwacom/${LINUXWACOM}/src/util/ \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}
	@${INSTALL} ${WRKDIR}/linuxwacom/${LINUXWACOM}/src/xdrv/wacom_drv.so \
		${PREFIX}/${XINPUTMODDIR}/
	@${INSTALL_MAN} ${WRKDIR}/linuxwacom/${LINUXWACOM}/src/wacom.4x.gz \
		${PREFIX}/${MAN4DIR}/

plist: clean configure
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
	@cd ${WRKDIR}/linuxwacom \
		&& ${SETENV} ${MAKE_ENV} PREFIX=${WRKDIR}/plist ./run_configure
	@${MKDIR} ${WRKDIR}/plist
	@cd ${WRKDIR}/${LINUXWACOM}/src/util \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}
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

.include <bsd.port.mk>
