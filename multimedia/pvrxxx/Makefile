# New ports collection makefile for:	pvrxxx
# Date created:				22 August 2006
# Whom:					usleepless <usleepless@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pvrxxx
PORTVERSION=	20060822
CATEGORIES=	multimedia kld
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTFILES=	${CXMSHAR} ${PVRTOOLS}.tar.gz hcwPVRP2.sys HcwMakoA.ROM pvrxxx_gpl.tgz
IGNOREFILES=	hcwPVRP2.sys	# Varies from month to month

MAINTAINER=	usleep@gmail.com
COMMENT=	Hauppauge PVR-150/500 TV cards driver for the cxm device, based on the pv250-port

CONFLICTS=	pvr250-*

PVRTOOLS=	pvr250-1.2
CXMSHAR=	cxm-20051030.shar

WRKSRC=		${WRKDIR}
NOFETCHFILES=	hcwPVRP2.sys HcwMakoA.ROM

RESTRICTED_FILES=	hcwPVRP2.sys HcwMakoA.ROM
RESTRICTED=	This port uses a binary driver which is owned by Hauppauge
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

MAN4=		cxm.4
MAN1=		pvr250-setchannel.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
MODULESDIR=	/modules
.else
MODULESDIR=	/boot/modules
.endif
PLIST_SUB=	MODULESDIR=${MODULESDIR}

.if !exists(${DISTDIR}/hcwPVRP2.sys)
IGNORE=		You need the file hcwPVRP2.sys from the CD coming with the PVR-150/500 card. Please place this file in ${DISTDIR} and run make again. Check http://ivtvdriver.org/index.php/Firmware for the recommended version.
.endif

.if !exists(${DISTDIR}/HcwMakoA.ROM)
IGNORE=         You need the file HcwMakoA.ROM from the CD coming with the PVR-150/500 card. Please place this file in ${DISTDIR} and run m
ake again. Check http://ivtvdriver.org/index.php/Firmware for the recommended version.
.endif

.if !exists(/usr/src/sys/dev/iicbus/iicbb.c)
IGNORE=		You need the kernel sources installed to build this module.
.endif

patch-iicbb:
.if ${OSVERSION} < 500000
	@if [ -z "`${GREP} cxm_iic /usr/src/sys/dev/iicbus/iicbb.c`" ]; then \
	    ${PATCH} -d/sys <${WRKDIR}/dev/cxm/Patch.iicbb-fbsd4; \
	    ${ECHO_CMD} "Patched /usr/src/sys/dev/iicbus/iicbb.c"; \
	else \
	    ${ECHO_CMD} "/usr/src/sys/dev/iicbus/iicbb.c was already patched"; \
	fi
.else
	@if [ -z "`${GREP} cxm_iic /usr/src/sys/dev/iicbus/iicbb.c`" ]; then \
	    ${PATCH} -d/sys <${WRKDIR}/dev/cxm/Patch.iicbb-fbsd5; \
	    ${ECHO_CMD} "Patched /usr/src/sys/dev/iicbus/iicbb.c"; \
	else \
	    ${ECHO_CMD} "/usr/src/sys/dev/iicbus/iicbb.c was already patched"; \
	fi
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR}; \
	${SH} ${DISTDIR}/${CXMSHAR}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PVRTOOLS}.tar.gz ${EXTRACT_AFTER_ARGS}; \
	cd modules/cxm/cxm; \
        ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/pvrxxx_gpl.tgz ${EXTRACT_AFTER_ARGS};

post-patch:
.if ${OSVERSION} < 500000
	${REINPLACE_CMD} -e 's/cxm0/bktr0/' \
		${WRKDIR}/${PVRTOOLS}/setchannel.c
	${REINPLACE_CMD} -e 's/tuner0/bktr0/' \
		${WRKDIR}/${PVRTOOLS}/setchannel.c
.else
	${REINPLACE_CMD} -e 's/tuner0/cxm0/' \
		${WRKDIR}/${PVRTOOLS}/setchannel.c
.endif

do-configure:
	cd ${WRKDIR}/dev/cxm; \
	${CC} -Wall -o cxm_extract_fw cxm_extract_fw.c; \
	./cxm_extract_fw ${DISTDIR}/hcwPVRP2.sys; \
	cd ../../modules/cxm/cxm; \
	../../../dev/cxm/cxm_extract_fw ${DISTDIR}/HcwMakoA.ROM;

do-build:
	cd ${WRKDIR}/modules/cxm; ${MAKE}
	cd ${WRKDIR}/${PVRTOOLS}; ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKDIR}/modules/cxm/cxm/cxm.ko ${MODULESDIR}
	${INSTALL_DATA} ${WRKDIR}/modules/cxm/cxm_iic/cxm_iic.ko ${MODULESDIR}
	${INSTALL_MAN} ${WRKDIR}/${PVRTOOLS}/cxm.4 ${PREFIX}/man/man4/cxm.4
	${INSTALL_MAN} ${WRKDIR}/${PVRTOOLS}/pvr250-setchannel.1 ${PREFIX}/man/man1/pvr250-setchannel.1
	${INSTALL_PROGRAM} ${WRKDIR}/${PVRTOOLS}/setchannel ${PREFIX}/bin/pvr250-setchannel
.if ${OSVERSION} < 500000
	cd /dev; \
	./MAKEDEV bktr0
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
