# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qpdfview
PORTVERSION=	0.4.3
CATEGORIES=	print
MASTER_SITES=	https://launchpadlibrarian.net/140746246/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Tabbed DjVu/PDF/PS document viewer

LICENSE=	GPLv2

USES=		desktop-file-utils pkgconfig qmake
USE_QT4=	corelib dbus gui imageformats_run linguist_build moc_build \
		rcc_build sql sql-sqlite3_run svg xml
QMAKE_ARGS+=	QMAKE_CFLAGS_RELEASE="" QMAKE_CXXFLAGS_RELEASE=""
QMAKE_SOURCE_PATH=	${PORTNAME}.pro

DATADIR=	${PREFIX}/share/${PORTNAME}

OPTIONS_DEFINE=	CUPS
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	DJVU PDF PS
BACKEND_DESC=	Documents support
OPTIONS_DEFAULT=	CUPS PDF
OPTIONS_SUB=	yes

CUPS_QMAKE_OFF=	"CONFIG+=without_cups"
CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

DJVU_LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre
DJVU_QMAKE_OFF=	"CONFIG+=without_djvu"

PDF_LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4
PDF_QMAKE_OFF=	"CONFIG+=without_pdf"

PS_LIB_DEPENDS=	libspectre.so:${PORTSDIR}/print/libspectre
PS_QMAKE_OFF=	"CONFIG+=without_ps"

pre-configure:
	${REINPLACE_CMD} -e 's#/usr#${PREFIX}#g;s#${PREFIX}/share/man#${PREFIX}/man#g' \
		${WRKSRC}/${PORTNAME}.pri
	cd ${WRKSRC} && ${LRELEASE} ${PORTNAME}.pro

.include <bsd.port.mk>
