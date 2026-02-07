PORTNAME=	qrcodegen
DISTVERSION=	1.14.2
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GUI to generate QR codes
WWW=		https://sites.google.com/site/qrcodeforwn/home/qr-code-generator-for-wireless-networks

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java zip
JAVA_VERSION=	8

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

INSTALLFILES=	FAQ.txt Installation.txt NOTICE QRCodeGen.jar Version.html

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${INSTALLFILES:C|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
