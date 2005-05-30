# New ports collection makefile for:	mercury
# Date created:			1 May 2005
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	mercury
DISTVERSION=	1709_RC8
CATEGORIES=	net java
MASTER_SITES=	http://download.mercury.to/	\
		${MASTER_SITE_LOCAL}
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
JAVA_VERSION=	1.4+
NO_BUILD=	yes

JMF_JARS=	customizer jmf mediaplayer multiplayer

SUB_FILES=	Mercury_Messenger
SUB_LIST=	JAVA_VERSION="${JAVA_VERSION}" JMF_JARS="${JMF_JARS:S|$|.jar|}"

LINSTDIR?=	share/Mercury
INSTDIR=	${PREFIX}/${LINSTDIR}
PLIST_SUB=	INSTDIR=${LINSTDIR}
SUB_DIRS=	lib resources

do-install:
	${MKDIR} ${INSTDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${INSTDIR}
	${LN} -sf ${INSTDIR}/${SUB_FILES} ${PREFIX}/bin
.for sd in ${SUB_DIRS}
	cd ${WRKDIR} && ${FIND} ${sd} -type d -exec ${MKDIR} ${INSTDIR}/{} \;
	cd ${WRKDIR} && ${FIND} ${sd} -type f -exec ${INSTALL_DATA} {} ${INSTDIR}/{} \;
.endfor

.include <bsd.port.mk>
