# New ports collection makefile for:	firefox-remote
# Date created:				13 May 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	20040803
CATEGORIES=	www
MASTER_SITES=	http://www.webonaut.com/distfiles/${PORTNAME}${PKGNAMESUFFIX}/
PKGNAMESUFFIX=	-remote
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	Wrapper scripts for firefox web browser

USE_BZIP2=	yes
USE_X_PREFIX=	yes

UTF8_HACK=	no
FIREFOX_REMOTE=	${PORTNAME}${PKGNAMESUFFIX}
THUNDERBIRD_REMOTE=	thunderbird${PKGNAMESUFFIX}

OPTIONS=UTF8_LOCALE "Use UTF8 locale (read Makefile for details)" off \
	MENU_FIREFOX "Add GNOME menu entry for firefox" off \
	MENU_THUNDERBIRD "Add GNOME menu entry for thunderbird" off

.include <bsd.port.pre.mk>

# firefox/thunderbird can't display unicode filenames with special
# characters like umlaute in german correctly if a ISO-locale is set.
# when enabled the remote scripts try to switch to the UTF8-locale if
# available (e.g. de_DE.UTF8 instead of de_DE.ISO8859-xx)
.if defined(WITH_UTF8_LOCALE)
UTF8_HACK=	yes
.endif

.if defined(WITH_MENU_FIREFOX)
PLIST_SUB+=	MENU_FIREFOX=""
.else
PLIST_SUB+=	MENU_FIREFOX="@comment "
.endif

.if defined(WITH_MENU_THUNDERBIRD)
PLIST_SUB+=	MENU_THUNDERBIRD=""
.else
PLIST_SUB+=	MENU_THUNDERBIRD="@comment "
.endif

do-build:
	@${REINPLACE_CMD} -e 's|@X11BASE@|${PREFIX}|g' \
		${WRKSRC}/${FIREFOX_REMOTE}
	@${REINPLACE_CMD} -e 's|@UTF8@|${UTF8_HACK}|g' \
		${WRKSRC}/${FIREFOX_REMOTE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${FIREFOX_REMOTE} \
		${PREFIX}/bin/${FIREFOX_REMOTE}
	${RM} -f ${PREFIX}/bin/${THUNDERBIRD_REMOTE}
	${LN} -s ${PREFIX}/bin/${FIREFOX_REMOTE} \
		${PREFIX}/bin/${THUNDERBIRD_REMOTE}
.if defined (WITH_MENU_FIREFOX)
	${INSTALL_DATA} ${WRKSRC}/mozilla_firefox.desktop \
		${X11BASE}/share/gnome/applications/
	${INSTALL_DATA} ${WRKSRC}/mozilla_firefox.png \
		${X11BASE}/share/gnome/pixmaps/
.endif
.if defined (WITH_MENU_THUNDERBIRD)
	${INSTALL_DATA} ${WRKSRC}/mozilla_thunderbird.desktop \
		${X11BASE}/share/gnome/applications/
	${INSTALL_DATA} ${WRKSRC}/mozilla_thunderbird.png \
		${X11BASE}/share/gnome/pixmaps/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
