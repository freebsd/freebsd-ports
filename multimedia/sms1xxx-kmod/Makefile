# New ports collection makefile for:	sms1xxx-kmod
# Date created:				10 February 2010
# Whom:					Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	sms1xxx
PORTVERSION=	20100624
CATEGORIES=	multimedia kld
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-siano/
PKGNAMESUFFIX=	-kmod
DISTNAME=	siano-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Native FreeBSD driver for Siano-based USB DVB devices

WRKSRC=	${WRKDIR}/siano-${PORTVERSION}

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	RC5WATCH "Build rc5watch utility" on \
		STELLAR "Build Stellar firmware" off \
		NOVA "Build Nova firmware" off \
		DEBUG "Build with debug symbols" off

ONLY_FOR_ARCHS=	i386 amd64

SUB_FILES=	pkg-message
KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

PORTDOCS=	CHANGELOG README COPYING

MAN4=	sms1xxx.4
MANCOMPRESSED=	yes

# Supported firmwares / firmwares to build
STELLAR_FW=	stellar_dvbt
NOVA_FW=	novab0_dvbbda
BUILD_FWS=

.include <bsd.port.pre.mk>

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.elif ${OSVERSION} <= 800063
IGNORE=		requires FreeBSD 8.0 or superior
.endif

.if defined(WITH_DEBUG)
ALL_TARGET=	debug
.endif

.if defined(WITH_RC5WATCH)
PLIST_SUB+=	PL_RC5WATCH=""
.else
PLIST_SUB+=	PL_RC5WATCH="@comment "
.endif

.if defined(WITH_STELLAR)
BUILD_FWS+=	${STELLAR_FW}
PLIST_SUB+=	PL_STELLAR=""
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw)
.if !defined(DISTFILE_INSTRUCTIONS)
DISTFILE_INSTRUCTIONS=\n\
	Due to licensing restrictions, firmware files must be fetched manually.\n
.endif
DISTFILE_INSTRUCTIONS+=	\
	\n- Please, get the appropriate firmware for your Stellar device\n\
	and copy the file to '${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw'\n\
	e.g. :\n\
	wget 'ftp://ftp.terratec.net/Receiver/Cinergy_Piranha/Update/Cinergy_Piranha_Drv_Vista_XP_3.09.02.00.exe'\n\
	unzip -j 'Cinergy_Piranha_Drv_Vista_XP_3.09.02.00.exe' \\\\\n\
	\t'Cinergy Piranha/BDA Driver 3.09.02.00/Windos XP (32Bit)/SMS100x_Dvbt.inp'\n\
	mv 'SMS100x_Dvbt.inp' '${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw'\n
.endif
.else
PLIST_SUB+=	PL_STELLAR="@comment "
.endif

.if defined(WITH_NOVA)
BUILD_FWS+=	${NOVA_FW}
PLIST_SUB+=	PL_NOVA=""
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw)
.if !defined(DISTFILE_INSTRUCTIONS)
DISTFILE_INSTRUCTIONS=\n\
	Due to licensing restrictions, firmware files must be fetched manually.\n
.endif
DISTFILE_INSTRUCTIONS+=	\
	\n- Please, get the appropriate firmware for your Nova device\n\
	and copy the file to '${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw'\n\
	e.g. :\n\
	wget 'http://www.wintvcd.co.uk/drivers/WinTV-MiniStick_4_2_26_28027_WHQL.zip'\n\
	unzip -j 'WinTV-MiniStick_4_2_26_28027_WHQL.zip' \\\\\n\
	\t'driver17/hcw17dvb.1b0'\n\
	mv 'hcw17dvb.1b0' '${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw'\n
.endif
.else
PLIST_SUB+=	PL_NOVA="@comment "
.endif

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SUBDIR=|SUBDIR= ${BUILD_FWS}|' \
		${WRKSRC}/firmwares/Makefile

pre-build:
.if defined(WITH_STELLAR)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw ${WRKSRC}/firmwares/${STELLAR_FW}/
.endif
.if defined(WITH_NOVA)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw ${WRKSRC}/firmwares/${NOVA_FW}/
.endif

post-build:
.if defined(WITH_RC5WATCH)
	 @cd ${WRKSRC}/apps/rc5watch/ && ${MAKE} all
.endif

post-install:
.if defined(WITH_RC5WATCH)
	${INSTALL_PROGRAM} ${WRKSRC}/apps/rc5watch/rc5watch ${PREFIX}/bin/rc5watch
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
