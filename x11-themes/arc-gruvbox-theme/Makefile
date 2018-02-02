# $FreeBSD$

PORTNAME=	arc-gruvbox
DISTVERSION=	g20161220
CATEGORIES=	x11-themes xfce
PKGNAMESUFFIX=	-theme

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Gruvbox variation on Arc Black Ubuntu theme

LICENSE=	GPLv3

GH_ACCOUNT=	Benoth
GH_PROJECT=	arc-variations

USE_GITHUB=	yes
GH_TAGNAME=	e3fc49d

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC_SUBDIR=	arc-gruvbox

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Arc-gruvbox
.for dir in gtk-2.0 gtk-3.0 metacity-1 unity xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} \
		${STAGEDIR}${PREFIX}/share/themes/Arc-gruvbox \
		"! -name thumbnail.png ! -name all-assets* ! -path *scss*"
.endfor
	${INSTALL_DATA} ${WRKSRC}/index.theme \
		${STAGEDIR}${PREFIX}/share/themes/Arc-gruvbox

.include <bsd.port.mk>
