# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	sms1xxx
PORTVERSION=	20120113
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-siano/
PKGNAMESUFFIX=	-kmod
DISTNAME=	siano-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Native FreeBSD driver for Siano-based USB DVB devices

LICENSE=	GPLv2

WRKSRC=	${WRKDIR}/siano-${PORTVERSION}

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	RC5WATCH DEBUG
OPTIONS_MULTI=	FIRMWARE
OPTIONS_MULTI_FIRMWARE=	STELLAR NOVA
OPTIONS_DEFAULT=	RC5WATCH NOVA
RC5WATCH_DESC=	Build rc5watch IR utility
STELLAR_DESC=	Build Terratec Cinergy Piranha FW
NOVA_DESC=	Build Hauppauge WinTV MiniStick FW

ONLY_FOR_ARCHS=	i386 amd64

SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG README COPYING

MAN4=	sms1xxx.4
MANCOMPRESSED=	yes

# Supported firmwares / firmwares to build
STELLAR_FW=	stellar_dvbt
NOVA_FW=	novab0_dvbbda
BUILD_FWS=

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800063
IGNORE=		requires FreeBSD 8.0 or superior
.endif

.if ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=	debug
.endif

.if ${PORT_OPTIONS:MRC5WATCH}
PLIST_SUB+=	PL_RC5WATCH=""
.else
PLIST_SUB+=	PL_RC5WATCH="@comment "
.endif

.if ${PORT_OPTIONS:MSTELLAR}
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

.if ${PORT_OPTIONS:MNOVA}
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

.if defined(DISTFILE_INSTRUCTIONS)
.if defined(PACKAGE_BUILDING)
IGNORE=	requires manual fetch
.else
pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SUBDIR=|SUBDIR= ${BUILD_FWS}|' \
		${WRKSRC}/firmwares/Makefile

pre-build:
.if ${PORT_OPTIONS:MSTELLAR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw ${WRKSRC}/firmwares/${STELLAR_FW}/
.endif
.if ${PORT_OPTIONS:MNOVA}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw ${WRKSRC}/firmwares/${NOVA_FW}/
.endif

post-build:
.if ${PORT_OPTIONS:MRC5WATCH}
	 @cd ${WRKSRC}/apps/rc5watch/ && ${MAKE} all
.endif

post-install:
.if ${PORT_OPTIONS:MRC5WATCH}
	${INSTALL_PROGRAM} ${WRKSRC}/apps/rc5watch/rc5watch ${PREFIX}/bin/rc5watch
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
