# ex:ts=8
# Ports collection makefile for:	ganttproject
# Date created:			Jul 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ganttproject
PORTVERSION=	1.9.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	-src.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plan projects using a Gantt chart

BUILD_DEPENDS=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_BUILD=	yes
JAVA_RUN=	yes
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}

PLIST_FILES=	bin/ganttproject %%JAVAJARDIR%%/ganttproject.jar

post-patch:
	@${SED} 's,%%JAVAJARDIR%%,${JAVAJARDIR},' ${FILESDIR}/${PORTNAME} > ${WRKSRC}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && ${ANT}

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
