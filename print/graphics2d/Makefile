PORTNAME=	graphics2d
DISTVERSION=	3.0.5
CATEGORIES=	print java
MASTER_SITES=	https://repo1.maven.org/maven2/de/rototor/pdfbox/${PORTNAME}/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Graphics2D Bridge for Apache PDFBox
WWW=		https://github.com/rototor/pdfbox-graphics2d

LICENSE=	APACHE20

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar	\
		%%JAVAJARDIR%%/${PORTNAME}-${PORTVERSION}.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.jar \
		 ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${LN} -sf ${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar

.include <bsd.port.mk>
