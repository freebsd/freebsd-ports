PORTNAME=	xml-commons
DISTVERSION=	1.4.01
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/xerces/${PORTNAME}/binaries
DISTNAME=	${PORTNAME}-external-${DISTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Provides common XML code for Apache projects

USE_JAVA=	yes
JAVA_RUN=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/xml-apis-ext.jar \
		${JAVAJARDIR}/xml-apis.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/xml-apis-ext.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/xml-apis.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
