PORTNAME=	qpdfview
DISTVERSION=	0.5.0
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION}/+download/
DISTNAME=	${PORTNAME}-0.5

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Tabbed DjVu/PDF/PS document viewer
WWW=		https://launchpad.net/qpdfview

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++17-lang desktop-file-utils gl pkgconfig qmake qt:5
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus gui imageformats linguisttools \
		printsupport sql sql-sqlite3 svg widgets xml buildtools:build
USE_CXXSTD=	c++17

QMAKE_SOURCE_PATH=	${PORTNAME}.pro

DATADIR=	${PREFIX}/share/${PORTNAME}

OPTIONS_DEFINE=		CUPS DJVU PS
OPTIONS_DEFAULT=	CUPS DJVU PS
OPTIONS_SUB=		yes

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_QMAKE_OFF=		"CONFIG+=without_cups"

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_QMAKE_OFF=		"CONFIG+=without_djvu"

PS_LIB_DEPENDS=	libspectre.so:print/libspectre
PS_QMAKE_OFF=	"CONFIG+=without_ps"

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e 's#/usr#${PREFIX}#g;s#${PREFIX}/share/man#${PREFIX}/man#g' \
		${WRKSRC}/${PORTNAME}.pri
	cd ${WRKSRC} && ${LRELEASE} ${PORTNAME}.pro

.include <bsd.port.mk>
