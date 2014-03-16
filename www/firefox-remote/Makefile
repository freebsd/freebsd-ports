# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	firefox-remote
PORTVERSION=	20040803
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper scripts for firefox web browser

USES=		tar:bzip2
UTF8_HACK=	no
FIREFOX_REMOTE=	firefox-remote
THUNDERBIRD_REMOTE=	thunderbird-remote

OPTIONS_DEFINE=	UTF8_LOCALE MENU_FIREFOX MENU_THUNDERBIRD
UTF8_LOCALE_DESC=	Use UTF8 locale (read Makefile for details)
MENU_FIREFOX_DESC=	Add menu entry for firefox
MENU_THUNDERBIRD_DESC=	Add menu entry for thunderbird

NO_STAGE=	yes
.include <bsd.port.options.mk>

# firefox/thunderbird can't display unicode filenames with special
# characters like umlaute in german correctly if a ISO-locale is set.
# when enabled the remote scripts try to switch to the UTF8-locale if
# available (e.g. de_DE.UTF8 instead of de_DE.ISO8859-xx)
.if ${PORT_OPTIONS:MUTF8_LOCALE}
UTF8_HACK=	yes
.endif

.if ${PORT_OPTIONS:MMENU_FIREFOX}
PLIST_SUB+=	MENU_FIREFOX=""
.else
PLIST_SUB+=	MENU_FIREFOX="@comment "
.endif

.if ${PORT_OPTIONS:MMENU_THUNDERBIRD}
PLIST_SUB+=	MENU_THUNDERBIRD=""
.else
PLIST_SUB+=	MENU_THUNDERBIRD="@comment "
.endif

do-build:
	@${REINPLACE_CMD} -e 's|@X11BASE@|${LOCALBASE}|g' \
		${WRKSRC}/${FIREFOX_REMOTE}
	@${REINPLACE_CMD} -e 's|@UTF8@|${UTF8_HACK}|g' \
		${WRKSRC}/${FIREFOX_REMOTE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${FIREFOX_REMOTE} \
		${PREFIX}/bin/${FIREFOX_REMOTE}
	${RM} -f ${PREFIX}/bin/${THUNDERBIRD_REMOTE}
	${LN} -s ${PREFIX}/bin/${FIREFOX_REMOTE} \
		${PREFIX}/bin/${THUNDERBIRD_REMOTE}
.if ${PORT_OPTIONS:MMENU_FIREFOX}
	${INSTALL_DATA} ${WRKSRC}/mozilla_firefox.desktop \
		${LOCALBASE}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/mozilla_firefox.png \
		${LOCALBASE}/share/pixmaps/
.endif
.if ${PORT_OPTIONS:MMENU_THUNDERBIRD}
	${INSTALL_DATA} ${WRKSRC}/mozilla_thunderbird.desktop \
		${LOCALBASE}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/mozilla_thunderbird.png \
		${LOCALBASE}/share/pixmaps/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
