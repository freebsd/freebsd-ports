# Created by: Harald Wille <harald.wille@students.jku.at>
# $FreeBSD$

PORTNAME=		wmweather+
PORTVERSION=		2.11
PORTREVISION=	7
CATEGORIES=		misc windowmaker geography
MASTER_SITES=		SF/wmweatherplus/wmweather%2B/
DISTNAME=		wmweather%2B-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays current conditions and forecasts with icons and text

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		pcre:${PORTSDIR}/devel/pcre \
		tiff:${PORTSDIR}/graphics/tiff \
		Hermes:${PORTSDIR}/graphics/Hermes \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		gif.5:${PORTSDIR}/graphics/giflib

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_XORG=	xpm

CONFIGURE_ARGS+=	--with-libwraster=${LOCALBASE} \
			--with-libpcre=${LOCALBASE} \
			--with-libcurl=${LOCALBASE} \
			--with-xpm-includes=${LOCALBASE} \
			--with-xpm-libraries=${LOCALBASE}

OPTIONS_DEFINE=	WM EXAMPLES
OPTIONS_DEFAULT=	WM
WM_DESC=	Depend on Window Maker port (otherwise only libwraster)

MAN1=		wmweather+.1

PLIST_FILES=	bin/wmweather+

.include <bsd.port.options.mk>

CFLAGS:=	${CFLAGS:C/-O[0-9]/-O0/}

.if ${PORT_OPTIONS:MWM}
LIB_DEPENDS+=	wraster:${PORTSDIR}/x11-wm/windowmaker
.else
LIB_DEPENDS+=	wraster:${PORTSDIR}/x11-wm/libwraster
.endif

WRKSRC=	${WRKDIR}/wmweather+-${PORTVERSION}

post-patch:
	@${CP} ${WRKSRC}/wmweather+.c ${WRKSRC}/wmweather+.c.dist
	@${SED} -e "s#^void usage(int i) __THROW.*#void usage(int i);#" \
		${WRKSRC}/wmweather+.c.dist > ${WRKSRC}/wmweather+.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmweather+ ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmweather+.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/HINTS ${EXAMPLESDIR}/HINTS
	${INSTALL_DATA} ${WRKSRC}/example.conf ${EXAMPLESDIR}/example.conf
PLIST_FILES+=	${EXAMPLESDIR_REL}/HINTS
PLIST_FILES+=	${EXAMPLESDIR_REL}/example.conf
PLIST_DIRS+=	${EXAMPLESDIR_REL}
PM=		${WRKDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO} "===================================================" > ${PM}
	@${ECHO} "A sample configuration file has been copied to" >> ${PM}
	@${ECHO} "${EXAMPLESDIR}/example.conf" >> ${PM}
	@${ECHO} "" >> ${PM}
	@${ECHO} "Please copy it to ~/.wmweather+/conf and adjust it" >> ${PM}
	@${ECHO} "to your needs!" >> ${PM}
	@${ECHO} "===================================================" >> ${PM}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
