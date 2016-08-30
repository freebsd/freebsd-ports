# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	htmlcompressor
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML/XML Compressor

LICENSE=	APACHE20

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/htmlcompressor %%JAVAJARDIR%%/htmlcompressor.jar
SUB_FILES=	htmlcompressor
SUB_LIST+=	JAVA_VERSION=${JAVA_PORT_VERSION:R}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/htmlcompressor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/htmlcompressor ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
