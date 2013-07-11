# Created by: Harald Wille <harald.wille@students.jku.at>
# $FreeBSD$

PORTNAME=		wmweather+
PORTVERSION=		2.13
PORTREVISION=	1
CATEGORIES=		misc windowmaker geography
MASTER_SITES=		SF/wmweatherplus/wmweather%2B/
DISTNAME=		wmweather%2B-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Displays current conditions and forecasts with icons and text

LICENSE=	GPLv2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		pcre:${PORTSDIR}/devel/pcre \
		tiff:${PORTSDIR}/graphics/tiff \
		Hermes:${PORTSDIR}/graphics/Hermes \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		gif:${PORTSDIR}/graphics/giflib

WRKSRC=		${WRKDIR}/wmweather+-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		iconv
USE_XORG=	xpm

CONFIGURE_ARGS+=	--with-libwraster=${LOCALBASE} \
			--with-libpcre=${LOCALBASE} \
			--with-libcurl=${LOCALBASE} \
			--with-xpm-includes=${LOCALBASE} \
			--with-xpm-libraries=${LOCALBASE}

PORTEXAMPLES=	HINTS example.conf
PORTDOCS=	ChangeLog README

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES WM
WM_DESC=	Depend on Window Maker port (otherwise only libwraster)

MAN1=		wmweather+.1

PLIST_FILES=	bin/wmweather+

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWM}
LIB_DEPENDS+=	wraster:${PORTSDIR}/x11-wm/windowmaker
.else
LIB_DEPENDS+=	wraster:${PORTSDIR}/x11-wm/libwraster
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|void usage(int i) __THROW __attribute__ ((__noreturn__));|void usage(int i);|' \
		${WRKSRC}/wmweather+.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/HINTS ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.conf ${EXAMPLESDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
