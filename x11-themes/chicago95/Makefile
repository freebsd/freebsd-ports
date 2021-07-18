PORTNAME=	chicago95
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1-70
DISTVERSIONSUFFIX=	-gc97678a
CATEGORIES=	x11-themes

MAINTAINER=	evgeniy@khramtsov.org
COMMENT=	Classic Redmond theme

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	grassmunk
GH_PROJECT=	${NAME}

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	BACKGROUNDS CURSORS ICONS
OPTIONS_DEFAULT=BACKGROUNDS CURSORS ICONS
OPTIONS_SUB=	yes

BACKGROUNDS_DESC=Install background theme(s)
CURSORS_DESC=Install cursor theme(s)

ICONS_USES=	gnome
ICONS_VARS=	INSTALLS_ICONS=yes

NAME=		${PORTNAME:S/c/C/}
QT5CT=		share/qt5ct/colors
WALLDIR=	share/wallpapers/${NAME}

do-install:
	@cd ${WRKSRC}/Theme && \
		${COPYTREE_SHARE} ${NAME} ${STAGEDIR}${PREFIX}/share/themes
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT5CT}
	${INSTALL_DATA} ${WRKSRC}/Extras/${NAME}_qt.conf \
		${STAGEDIR}${PREFIX}/${QT5CT}

do-install-BACKGROUNDS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${WALLDIR}
	@cd ${WRKSRC}/Extras/Backgrounds && \
		${INSTALL_DATA} Patterns/* ${STAGEDIR}${PREFIX}/${WALLDIR} && \
		${INSTALL_DATA} Wallpaper/* ${STAGEDIR}${PREFIX}/${WALLDIR}

do-install-CURSORS-on:
	@cd ${WRKSRC}/Cursors && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons

do-install-ICONS-on:
	@cd ${WRKSRC}/Icons && \
		${COPYTREE_SHARE} ${NAME} ${STAGEDIR}${PREFIX}/share/icons

post-install: # autoplist: thousands of files, complex dependencies on options
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>

