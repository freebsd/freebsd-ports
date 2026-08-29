PORTNAME=	aporetic
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	Custom Iosevka fonts with modified style and metrics

LICENSE=	OFL11

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	protesilaos

EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/${PORTNAME}-*/TTF \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/${PORTNAME}-*/TTF-Unhinted \
			--strip-components 3 \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
