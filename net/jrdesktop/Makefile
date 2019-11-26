# Created by: gahr
# $FreeBSD$

PORTNAME=	jrdesktop
PORTVERSION=	0.3.1.0
CATEGORIES=	net java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R:R}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View and/or control a remote PC

LICENSE=	GPLv3

USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	jrdesktop
SUB_LIST+=	JAVA=${JAVA} \
		PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION}

PLIST_FILES=	${JAVAJARDIR:S/${PREFIX}\///}/${DISTNAME}.jar \
		bin/${PORTNAME}

post-extract:
	${CP} ${DISTDIR}/${DISTNAME}.jar ${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jrdesktop ${STAGEDIR}${PREFIX}/bin/jrdesktop

.include <bsd.port.mk>
