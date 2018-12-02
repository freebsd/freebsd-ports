# Created by: Yuan, Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kpdftool
PORTVERSION=	0.23.1
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTFILES=	33194-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple utility to manipulate PS and PDF files

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	convert:graphics/ImageMagick6

USE_QT=		qt3support moc_build porting_build uic3_build
USES=		ghostscript:run qmake qt:4 zip

DESKTOP_ENTRIES=	"KPDFTool" "${COMMENT}" "kpdftool" \
			"kpdftool" "Qt;Utility;" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>
