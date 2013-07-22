# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qpdfview
PORTVERSION=	0.4.3
CATEGORIES=	print
MASTER_SITES=	https://launchpadlibrarian.net/140746246/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Tabbed PDF viewer using the poppler library

LICENSE=	GPLv2

LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		cups:${PORTSDIR}/print/cups-client

USE_QT4=	corelib dbus gui imageformats linguist_build moc_build \
		qmake_build rcc_build sql sql-sqlite3_run svg xml
QMAKEFLAGS+=	QMAKE_CFLAGS_RELEASE="" QMAKE_CXXFLAGS_RELEASE=""

DATADIR=	${PREFIX}/share/${PORTNAME}

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	DJVU PDF PS
DJVU_DESC=	DjVu support
PS_DESC=	PostScript support
OPTIONS_DEFAULT=	PDF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDJVU}
PLIST_SUB+=	DJVU=""
LIB_DEPENDS+=	djvulibre:${PORTSDIR}/graphics/djvulibre
.else
QMAKEFLAGS+=	"CONFIG+=without_djvu"
PLIST_SUB+=	DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MPDF}
PLIST_SUB+=	PDF=""
.else
QMAKEFLAGS+=	"CONFIG+=without_pdf"
PLIST_SUB+=	PDF="@comment "
.endif

.if ${PORT_OPTIONS:MPS}
PLIST_SUB+=	PS=""
LIB_DEPENDS+=	spectre:${PORTSDIR}/print/libspectre
.else
QMAKEFLAGS+=	"CONFIG+=without_ps"
PLIST_SUB+=	PS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's#/usr#${PREFIX}#g;s#${PREFIX}/share/man#${PREFIX}/man#g' \
		${WRKSRC}/${PORTNAME}.pri

do-configure:
	cd ${WRKSRC} && lrelease-qt4 ${PORTNAME}.pro
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS} ${PORTNAME}.pro

.include <bsd.port.mk>
