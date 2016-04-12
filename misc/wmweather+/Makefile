# Created by: Harald Wille <harald.wille@students.jku.at>
# $FreeBSD$

PORTNAME=	wmweather+
PORTVERSION=	2.15
PORTREVISION=	4
CATEGORIES=	misc windowmaker geography
MASTER_SITES=	SF/wmweatherplus/wmweather%2B/ \
		SF/nemysisfreebsdp/misc/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays current conditions and forecasts with icons and text

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libtiff.so:graphics/tiff \
		libHermes.so:graphics/Hermes \
		libpng.so:graphics/png \
		libgif.so:graphics/giflib

WRKSRC=		${WRKDIR}/wmweather+-${PORTVERSION}

USES=		iconv jpeg
USE_XORG=	xpm
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm
CONFIGURE_ARGS+=	--with-libwraster=${LOCALBASE} \
			--with-libpcre=${LOCALBASE} \
			--with-libcurl=${LOCALBASE} \
			--with-xpm-includes=${LOCALBASE} \
			--with-xpm-libraries=${LOCALBASE}

SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	ChangeLog README
PORTEXAMPLES=	HINTS example.conf

OPTIONS_DEFINE=	DOCS EXAMPLES WM
WM_DESC=	Depend on Window Maker port (otherwise only libwraster)

DESKTOP_ENTRIES="${PORTNAME}" "" "${PORTNAME}" \
		"${PORTNAME}" "System;Monitor;" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWM}
LIB_DEPENDS+=	libWMaker.so:x11-wm/windowmaker
.else
LIB_DEPENDS+=	libwraster.so:x11-wm/libwraster
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| __THROW __attribute__ ((__noreturn__))|| ; \
		s|http://www.nws.noaa.gov/tg/siteloc.shtml|http://www.nws.noaa.gov/tg/siteloc.php|' \
		${WRKSRC}/${PORTNAME}.c
	@${REINPLACE_CMD} -e \
		's|http://www.nws.noaa.gov/tg/siteloc.shtml|http://www.nws.noaa.gov/tg/siteloc.php|' \
		${WRKSRC}/${PORTNAME}.1.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
