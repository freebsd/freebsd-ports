PORTNAME=	fluxbox-tenr-styles-pack
PORTVERSION=	20190912
CATEGORIES=	x11-themes
MASTER_SITES=	http://tenr.de/styles/archives/
DISTNAME=	tenr.de-styles-pkg_${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Tenner themes pack for fluxbox

RUN_DEPENDS=	fluxbox:x11-wm/fluxbox

USES=	tar:bzip2 xorg

INSTALL_DIR=	${PREFIX}/share/fluxbox/styles/

USE_XORG=	x11
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/tenr.de-styles-pkg

post-extract:
.for theme in arch bloe bora_black bora_blue bora_green carp green_tea ostrich zimek_bisque zimek_darkblue zimek_green
	@${RM} -rf ${WRKSRC}/${theme}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${INSTALL_DIR}
	cd ${WRKSRC}; ${COPYTREE_SHARE} \* ${STAGEDIR}${INSTALL_DIR}

.include <bsd.port.mk>
