# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	xml-commons
PORTVERSION=	1.4.01
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/xml/commons
DISTNAME=	${PORTNAME}-external-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides common XML code for Apache projects

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/xml-apis-ext.jar \
		%%JAVAJARDIR%%/xml-apis.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/xml-apis-ext.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/xml-apis.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
