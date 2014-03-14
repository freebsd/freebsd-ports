# Created by: Yuan, Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kpdftool
PORTVERSION=	0.23.1
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTFILES=	33194-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Simple utility to manipulate PS and PDF files

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_QT4=	qt3support moc_build porting_build uic3_build
USE_GHOSTSCRIPT_RUN=	yes
USES=		qmake zip

DESKTOP_ENTRIES=	"KPDFTool" "${COMMENT}" "kpdftool" \
			"kpdftool" "Qt;Utility;" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>
