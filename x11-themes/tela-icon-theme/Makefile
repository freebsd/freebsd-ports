PORTNAME=	tela-icon-theme
DISTVERSION=	2025-02-10
CATEGORIES=	x11-themes

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Flat icon theme
WWW=		https://github.com/vinceliuice/Tela-icon-theme

LICENSE=	GPLv3

RUN_DEPENDS=	hicolor-icon-theme>0:misc/hicolor-icon-theme \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	${PORTNAME:C/t/T/1}

NO_ARCH=	yes
NO_BUILD=	yes

ICONSDIR=	${PREFIX}/share/icons
THEME_NAME=	Tela

pre-install:
	${MKDIR} ${STAGEDIR}${ICONSDIR}/${THEME_NAME}

do-install:
	${REINPLACE_CMD} -i "" -e 's|%NAME%|${THEME_NAME}|' \
		${WRKSRC}/src/index.theme

	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ICONSDIR}/${THEME_NAME} "! -name *\.orig"

	cd ${WRKSRC}/links && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ICONSDIR}/${THEME_NAME}

post-install:
.for d in 16 22 24 32 scalable
	${RLN} ${STAGEDIR}${ICONSDIR}/${THEME_NAME}/${d} \
		"${STAGEDIR}${ICONSDIR}/${THEME_NAME}/${d}@2x"
.endfor

.include <bsd.port.mk>
