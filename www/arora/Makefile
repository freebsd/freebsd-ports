# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	arora
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	shanjobe@gmail.com
COMMENT=	Simple Qt4 based browser

LICENSE=	GPLv3

USE_QT4=	network webkit qmake_build moc_build uic_build rcc_build \
		imageformats gui script sql
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix -recursive PREFIX=${PREFIX}
MAKE_JOBS_SAFE=	yes

MAN1=		arora.1 arora-cacheinfo.1 arora-placesimport.1 htmlToXBel.1

.include <bsd.port.options.mk>

.if ${ARCH} == ia64
BROKEN=		core dump on application startup
.endif

.if ! ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS="@comment "
.else
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.endif

do-configure:
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
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-configure:
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} 's|raster||' ${WRKSRC}/src/main.cpp

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/data/arora.1 \
		${WRKSRC}/tools/cacheinfo/data/arora-cacheinfo.1 \
		${WRKSRC}/tools/htmlToXBel/data/htmlToXBel.1 \
		${WRKSRC}/tools/placesimport/data/arora-placesimport.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
