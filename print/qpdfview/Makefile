PORTNAME=	qpdfview
DISTVERSION=	0.5.0
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION}/+download/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.0$//}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Tabbed DjVu/PDF/PS document viewer
WWW=		https://launchpad.net/qpdfview

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-${FLAVOR}.so:graphics/poppler-${FLAVOR}

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		desktop-file-utils gl pkgconfig qmake
USE_LDCONFIG=	yes

.if ${FLAVOR} == "qt5"
PKGNAMESUFFIX=		-qt5
USES+=			compiler:c++17-lang qt:5
USE_GL=			gl
USE_QT=			concurrent core dbus gui linguisttools printsupport \
			sql svg widgets xml buildtools:build
CONFLICTS_INSTALL=	${PORTNAME}
.else
USES+=			compiler:c++11-lang qt:6
USE_GL=			opengl
USE_QT=			base svg tools:build
CONFLICTS_INSTALL=	${PORTNAME}-qt5
.endif

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

OPTIONS_DEFINE=		CUPS DJVU PS SYNCTEX
OPTIONS_DEFAULT=	CUPS DJVU PS
OPTIONS_SUB=		yes

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_QMAKE_OFF=		"CONFIG+=without_cups"

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_QMAKE_OFF=		"CONFIG+=without_djvu"

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_QMAKE_OFF=		"CONFIG+=without_ps"

SYNCTEX_DESC=		SyncTeX support
SYNCTEX_LIB_DEPENDS=	libsynctex.so:devel/tex-synctex
SYNCTEX_QMAKE_OFF=	"CONFIG+=without_synctex"

post-patch:
.if ${FLAVOR} == "qt5"
	${REINPLACE_CMD} -e '/CONFIG/s/c\+\+11/c++17/' \
		${WRKSRC}/${PORTNAME}.pri
.endif
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/${PORTNAME}.pri

pre-configure:
	cd ${WRKSRC} && ${LRELEASE} ${PORTNAME}.pro

.include <bsd.port.mk>
