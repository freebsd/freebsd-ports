PORTNAME=	openbox-arc-theme
PORTVERSION=	20170104
CATEGORIES=	x11-themes

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Arc Openbox theme

LICENSE=	GPLv3

RUN_DEPENDS=	openbox:x11-wm/openbox

USE_GITHUB=	yes
GH_ACCOUNT=	dglava
GH_PROJECT=	arc-openbox
GH_TAGNAME=	d6bfa0e

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
.for theme in Arc Arc-Dark Arc-Darker
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${theme} ${STAGEDIR}${PREFIX}/share/themes
.endfor

.include <bsd.port.mk>
