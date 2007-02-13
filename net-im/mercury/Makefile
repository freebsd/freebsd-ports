# New ports collection makefile for:	mercury
# Date created:			1 May 2005
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	mercury
DISTVERSION=	1.9RC2
PORTEPOCH=	6
CATEGORIES=	net-im java
MASTER_SITES=	${MASTER_SITE_LOCAL}			\
		http://download.mercury.to/1.9/		\
		http://dknapp.ca/mirror/mercury/beta/
MASTER_SITE_SUBDIR=	thierry/${PORTNAME}
DISTNAME=	${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

# Maintainership available: drop me a line if interested
MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java Based MSN client

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper	\
		jmfinit:${PORTSDIR}/java/jmf

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

JMF_JARS=	customizer jmf mediaplayer multiplayer

SUB_FILES=	Mercury_Messenger
SUB_LIST=	JAVA_VERSION="${JAVA_VERSION}" JMF_JARS="${JMF_JARS:S|$|.jar|}"

LINSTDIR?=	share/Mercury
INSTDIR=	${PREFIX}/${LINSTDIR}
PLIST_SUB=	INSTDIR=${LINSTDIR}
SUB_DIRS=	lib resources
DIR2PRUNE=	resources/AppData/Backgrounds	\
		resources/AppData/Games		\
		resources/AppData/Plugins

DESKTOP_ENTRIES="Mercury Messenger" "${COMMENT}"	\
		"${INSTDIR}/resources/online.png"	\
		"${SUB_FILES}" "" true

.if defined(WITH_VIDEO)	# Experimental
VIDJAR=		VidConf-libs.jar
EXTRACT_ONLY+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${VIDJAR}
PLIST_SUB+=	VID="" VIDJAR="${VIDJAR}"
.else
PLIST_SUB+=	VID="@comment " VIDJAR=""
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_TRAY=	yes
.endif

.if !defined(WITHOUT_TRAY)
LIB_DEPENDS+=	tray.0:${PORTSDIR}/x11-toolkits/jdic
.endif

post-extract:
	${MKDIR} ${WRKDIR}/icons
	cd ${WRKDIR}/icons &&	\
	${EXTRACT_CMD} ${WRKDIR}/resources/AppData/StatusIcons/MMercury.zip

do-install:
	${MKDIR} ${INSTDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${INSTDIR}
	${LN} -sf ${INSTDIR}/${SUB_FILES} ${PREFIX}/bin
.for sd in ${SUB_DIRS}
	cd ${WRKDIR} && ${FIND} ${sd} -type d -exec ${MKDIR} ${INSTDIR}/{} \;
	cd ${WRKDIR} && ${FIND} ${sd} -type f -exec ${INSTALL_DATA} {} ${INSTDIR}/{} \;
.endfor
	${INSTALL_DATA} ${WRKDIR}/icons/online.png ${INSTDIR}/resources
.for ed in ${DIR2PRUNE}
	${TOUCH} ${INSTDIR}/${ed}/.keep_me
.endfor
.if defined(WITH_VIDEO)
	${INSTALL_DATA} ${_DISTDIR}/${VIDJAR} ${INSTDIR}/lib
.endif

.include <bsd.port.post.mk>
