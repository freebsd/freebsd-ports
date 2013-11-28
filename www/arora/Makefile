# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	arora
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	shanjobe@gmail.com
COMMENT=	Simple Qt 4 based browser

LICENSE=	GPLv3

USES=		desktop-file-utils qmake
USE_QT4=	network webkit moc_build uic_build rcc_build \
		imageformats_run gui script sql

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USE=	QT4=linguist_build

BROKEN_ia64=		core dump on application startup

.include <bsd.port.options.mk>

pre-configure:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e "/INSTALLS/s|translations||" \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e "s|target_predeps||" \
		${WRKSRC}/src/locale/locale.pri
.endif
	@${REINPLACE_CMD} -e "/INSTALLS/s|man man-compress||" \
		${WRKSRC}/src/src.pro \
		${WRKSRC}/tools/cacheinfo/cacheinfo.pro \
		${WRKSRC}/tools/htmlToXBel/htmlToXBel.pro \
		${WRKSRC}/tools/placesimport/placesimport.pro
	@${REINPLACE_CMD} -e "/else/s|lrelease|lrelease-qt4|" \
		${WRKSRC}/src/locale/locale.pri
	@${REINPLACE_CMD} "/pkg-config/d" \
		${WRKSRC}/src/src.pro

post-configure:
	@${REINPLACE_CMD} 's|raster||' ${WRKSRC}/src/main.cpp

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/data/arora.1 \
		${WRKSRC}/tools/cacheinfo/data/arora-cacheinfo.1 \
		${WRKSRC}/tools/htmlToXBel/data/htmlToXBel.1 \
		${WRKSRC}/tools/placesimport/data/arora-placesimport.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
