# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	weka
DISTVERSION=	3-8-0
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-3-8/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Data Mining Software in Java

LICENSE=	GPLv2

PORTSCOUT=	limitw:1,even	# Second component is even for stable versions.

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${PORTNAME}.jar

PLIST_FILES=	%%DATADIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar \
		${STAGEDIR}${DATADIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
