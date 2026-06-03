PORTNAME=	qrcodegen
DISTVERSION=	1.14.2
PORTREVISION=	5
CATEGORIES=	textproc java
MASTER_SITES=	LOCAL/ronald \
		https://repo1.maven.org/maven2/com/sun/xml/bind/jaxb-ri/2.3.1/:jaxb
DISTFILES=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX} \
		jaxb-ri-2.3.1.zip:jaxb
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GUI to generate QR codes
WWW=		https://sites.google.com/site/qrcodeforwn/home/qr-code-generator-for-wireless-networks

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java zip

DESKTOP_ENTRIES=	"Portable QR-Code Generator" \
			"${COMMENT}" \
			"" \
			"${PORTNAME}" \
			"Utility;2DGraphics;Java;" \
			false
EXTRACT_BEFORE_ARGS=	-jqo
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}
SUB_LIST=	JAVA=${JAVA} JAXB_FILES="${JAXB_FILES}"

INSTALLFILES=	FAQ.txt Installation.txt NOTICE QRCodeGen.jar Version.html
JAXB_FILES=	jaxb-api.jar jaxb-runtime.jar istack-commons-runtime.jar javax.activation-api.jar

post-extract:
	unzip -q -d ${WRKDIR}/jaxb ${DISTDIR}/jaxb-ri-2.3.1.zip

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${INSTALLFILES:C|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${JAXB_FILES:C|^|${WRKDIR}/jaxb/jaxb-ri/mod/|} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
