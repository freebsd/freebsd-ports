PORTNAME=	jcef
DISTVERSION=	146.0.10	# To be supported by math/scilab !!!
CATEGORIES=	www java
MASTER_SITES=	https://github.com/jcefmaven/jcefmaven/releases/download/${PORTVERSION}/
DISTNAME=	jcef-api-jcef-${JCEF_TAG}+cef-${CEF_VERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java Chromium Embedded Framework
WWW=		https://github.com/chromiumembedded/java-cef

LICENSE=	APACHE20

USES=		java:run

JCEF_TAG=	d3de827
CEF_TAG=	g8219561
CHROMIUM_VER=	146.0.7680.179
CEF_VERSION=	${PORTVERSION}+${CEF_TAG}+chromium-${CHROMIUM_VER}

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
