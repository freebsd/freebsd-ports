# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qpdfview
DISTVERSION=	0.4.17beta1
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	https://launchpadlibrarian.net/294276875/ \
		https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION}/+download/

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Tabbed DjVu/PDF/PS document viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake qt:5
USE_LDCONFIG=	yes
USE_QT=		buildtools_build concurrent imageformats linguisttools printsupport sql sql-sqlite3 svg xml
QMAKE_SOURCE_PATH=	${PORTNAME}.pro

DATADIR=	${PREFIX}/share/${PORTNAME}

OPTIONS_DEFINE=	CUPS
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	DJVU PS
BACKEND_DESC=	Additional documents support
OPTIONS_DEFAULT=	CUPS PS
OPTIONS_SUB=	yes

CUPS_QMAKE_OFF=	"CONFIG+=without_cups"
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_QMAKE_OFF=	"CONFIG+=without_djvu"

PS_LIB_DEPENDS=	libspectre.so:print/libspectre
PS_QMAKE_OFF=	"CONFIG+=without_ps"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

pre-configure:
	${REINPLACE_CMD} -e 's#/usr#${PREFIX}#g;s#${PREFIX}/share/man#${PREFIX}/man#g' \
		${WRKSRC}/${PORTNAME}.pri
	cd ${WRKSRC} && ${LRELEASE} ${PORTNAME}.pro

.include <bsd.port.mk>
