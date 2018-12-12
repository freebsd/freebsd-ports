# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qpdfview
DISTVERSION=	0.4.17beta1
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	https://launchpadlibrarian.net/294276875/ \
		https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION}/+download/

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Tabbed DjVu/PDF/PS document viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake
USE_LDCONFIG=	yes
QMAKE_SOURCE_PATH=	${PORTNAME}.pro

DATADIR=	${PREFIX}/share/${PORTNAME}

OPTIONS_SINGLE=	TOOLKITS
OPTIONS_SINGLE_TOOLKITS=	QT4 QT5
OPTIONS_DEFINE=	CUPS
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	DJVU PS
BACKEND_DESC=	Additional documents support
OPTIONS_DEFAULT=	QT5 CUPS PS
OPTIONS_SUB=	yes

CUPS_QMAKE_OFF=	"CONFIG+=without_cups"
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_QMAKE_OFF=	"CONFIG+=without_djvu"

QT4_USES=	qt:4
QT4_USE=	qt=dbus,gui,imageformats,linguisttools,moc_build,rcc_build,sql,sql-sqlite3,svg,xml
QT4_LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4

QT5_USES=	qt:5
QT5_USE=	qt=buildtools_build,concurrent,imageformats,linguisttools,printsupport,sql,sql-sqlite3,svg,xml
QT5_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

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
