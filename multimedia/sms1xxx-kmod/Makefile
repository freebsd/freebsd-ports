# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	sms1xxx
PORTVERSION=	20120113
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-siano/
PKGNAMESUFFIX=	-kmod
DISTNAME=	siano-${PORTVERSION}
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
OPTIONS_SUB=	yes
RC5WATCH_DESC=	Build rc5watch IR utility
DEBUG_ALL_TARGET=	debug
STELLAR_DESC=	Build Terratec Cinergy Piranha FW
NOVA_DESC=	Build Hauppauge WinTV MiniStick FW

ONLY_FOR_ARCHS=	i386 amd64

SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG README COPYING

# Supported firmwares / firmwares to build
STELLAR_FW=	stellar_dvbt
NOVA_FW=	novab0_dvbbda
BUILD_FWS=

USES=		kmod tar:tgz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTELLAR}
BUILD_FWS+=	${STELLAR_FW}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw)
.if !defined(DISTFILE_INSTRUCTIONS)
DISTFILE_INSTRUCTIONS=\n\
	Due to licensing restrictions, firmware files must be fetched manually.\n
.endif
DISTFILE_INSTRUCTIONS+=	\
	\n- Please, get the appropriate firmware for your Stellar device\n\
	and copy the file to '${DISTDIR}/${DIST_SUBDIR}/${STELLAR_FW}.fw'\n
.endif
.endif

.if ${PORT_OPTIONS:MNOVA}
BUILD_FWS+=	${NOVA_FW}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw)
.if !defined(DISTFILE_INSTRUCTIONS)
DISTFILE_INSTRUCTIONS=\n\
	Due to licensing restrictions, firmware files must be fetched manually.\n
.endif
DISTFILE_INSTRUCTIONS+=	\
	\n- Please, get the appropriate firmware for your Nova device\n\
	and copy the file to '${DISTDIR}/${DIST_SUBDIR}/${NOVA_FW}.fw'\n
.endif
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
	${INSTALL_PROGRAM} ${WRKSRC}/apps/rc5watch/rc5watch ${STAGEDIR}${PREFIX}/bin/rc5watch
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
