#
# New ports collection makefile for:	pvr250
# Date created:				10 October 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	pvr250
PORTVERSION=	200408
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTFILES=	cxm-200408.shar hcwPVRP2.sys

MAINTAINER=	edwin@mavetju.org
COMMENT=	Hauppauge PVR-250/260 TV cards driver for the cxm device

WRKSRC=		${WRKDIR}

RESTRICTED_FILES=	hcwPVRP2.sys
RESTRICTED=	"This port uses a binary driver which is owned by Hauppauge"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

OPTIONS=	USBROADCAST	"US Broadcast"	Off \
		USCABLE		"US Cable" Off \
		BGBROADCAST	"B/G Broadcast" Off \
		BGAUSTRALIA	"B/G Australia" Off \
		IBROADCAST	"I Broadcast" Off \
		LBROADCAST	"L Broadcast" Off

pre-everything::
	@${ECHO_CMD} "Some tuners (for example the Philips FQ1216M) supports multiple standards."
	@${ECHO_CMD} "Use the following configuration screen (or 'make config') to choose your local  TV channel system if you have such a tuner."
	@${ECHO_CMD} "At this moment only the Philips FQ1216M is known to do this. If you don't have  one, just ignore it. If you have one, select one (1) entry."
	@sleep 5

.include <bsd.port.pre.mk>

.if defined(WITH_USBROADCAST)
EXTRA_PATCHES=	${FILESDIR}/patchtuner-usbroadcast
.endif
.if defined(WITH_USCABLE)
EXTRA_PATCHES=	${FILESDIR}/patchtuner-uscable
.endif
.if defined(WITH_BGBROADCAST)
EXTRA_PATCHES=	${FILESDIR}/patchtuner-bgbroadcast
.endif
.if defined(WITH_BGAUSTRALIA)
EXTRA_PATCHES=	${FILESDIR}/patchtuner-bgaustralia
.endif
.if defined(WITH_IBROADCAST)
EXTRA_PATCHES=	${FILESDIR}/patchtuner-ibroadcast
.endif
.if defined(WITH_LBROADCAST)
EXTRA_PATCHES=	${FILESDIR}/patchtuner-lbroadcast
.endif

.if ${OSVERSION} < 500000
PREFIX=		/modules
.else
PREFIX=		/boot/kernel
.endif

.if !exists(${DISTDIR}/hcwPVRP2.sys)
BROKEN=		You need the file hcwPVRP2.sys from the CD coming with the PVR-250/350 card. Please place this file in ${DISTDIR} and run make again.
.endif

.if !exists(/usr/src/sys/dev/iicbus/iicbb.c)
IGNORE=		You need the kernel sources installed to build this module.
.endif

patch-iicbb:
.if ${OSVERSION} < 500000
	@if [ -z "`${GREP} cxm_iic /usr/src/sys/dev/iicbus/iicbb.c`" ]; then \
	    ${PATCH} /usr/src/sys/dev/iicbus/iicbb.c ${WRKDIR}/dev/cxm/Patch.iicbb-fbsd4; \
	    ${ECHO_CMD} "Patched /usr/src/sys/dev/iicbus/iicbb.c"; \
	else \
	    ${ECHO_CMD} "/usr/src/sys/dev/iicbus/iicbb.c was already patched"; \
	fi
.else
	@if [ -z "`${GREP} cxm_iic /usr/src/sys/dev/iicbus/iicbb.c`" ]; then \
	    ${PATCH} /usr/src/sys/dev/iicbus/iicbb.c ${WRKDIR}/dev/cxm/Patch.iicbb-fbsd5; \
	    ${ECHO_CMD} "Patched /usr/src/sys/dev/iicbus/iicbb.c"; \
	else \
	    ${ECHO_CMD} "/usr/src/sys/dev/iicbus/iicbb.c was already patched"; \
	fi
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR}; \
	${SH} ${DISTDIR}/cxm-200408.shar

do-configure:
	cd ${WRKDIR}/dev/cxm; \
	${CC} -Wall -o cxm_extract_fw cxm_extract_fw.c; \
	./cxm_extract_fw ${DISTDIR}/hcwPVRP2.sys

do-build:
	cd ${WRKDIR}/modules/cxm; \
	${MAKE}

do-install:
	${INSTALL_DATA} ${WRKDIR}/modules/cxm/cxm/cxm.ko ${PREFIX}
	${INSTALL_DATA} ${WRKDIR}/modules/cxm/cxm_iic/cxm_iic.ko ${PREFIX}
.if ${OSVERSION} < 500000
	cd /dev; \
	./MAKEDEV bktr0
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
