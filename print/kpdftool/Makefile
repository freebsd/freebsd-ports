# Created by: Yuan, Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kpdftool
PORTVERSION=	0.23.1
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTFILES=	33194-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Simple utility to manipulate PS and PDF files

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_ZIP=	yes
USE_QT4=	qt3support moc_build porting_build qmake_build uic3_build
USE_GHOSTSCRIPT_RUN=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES=	"KPDFTool" "${COMMENT}" "kpdftool" \
			"kpdftool" "Qt;Utility;" false

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	cd ${WRKSRC}/icons && ${COPYTREE_SHARE} hicolor ${PREFIX}/share/icons/

.include <bsd.port.mk>
