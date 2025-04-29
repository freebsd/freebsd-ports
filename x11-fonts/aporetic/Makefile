PORTNAME=	aporetic
DISTVERSION=	1.2.0
CATEGORIES=	x11-fonts

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	Custom Iosevka fonts with modified style and metrics

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	protesilaos

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} aporetic\* ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
