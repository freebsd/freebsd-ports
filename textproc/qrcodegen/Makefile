# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qrcodegen
PORTVERSION=	1.14.2
CATEGORIES=	textproc java
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	GUI to generate QR codes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes
USES=		zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	qrcodegen

INSTALLFILES=	FAQ.txt Installation.txt NOTICE QRCodeGen.jar Version.html

DESKTOP_ENTRIES="Portable QR-Code Generator" \
		"${COMMENT}" \
		"" \
		"qrcodegen" \
		"Utility;2DGraphics;Java;" \
		false

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${UNZIP_CMD} -q -j -d ${WRKSRC} ${DISTDIR}/${EXTRACT_ONLY}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in ${INSTALLFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}/
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
