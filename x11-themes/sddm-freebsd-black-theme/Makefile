PORTNAME=	sddm-freebsd-black-theme
DISTVERSION=	1.4
CATEGORIES=	x11-themes

MAINTAINER=	mxd@mxdyeah.com
COMMENT=	Simple SDDM theme inspired on the FBSD SLiM theme
WWW=		https://github.com/mxdabc/sddm-freebsd-black-theme

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	montserrat>=0:x11-fonts/montserrat

USE_GITHUB=	yes
GH_ACCOUNT=	mxdabc

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	AUTHORS CHANGELOG TRADEMARKS
PLIST_SUB=	THEMEDIR=${THEMEDIR_REL}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

THEMEDIR_REL=	share/sddm/themes/sddm-freebsd-black-theme
THEMEDIR=	${PREFIX}/${THEMEDIR_REL}

do-install:
	${MKDIR} ${STAGEDIR}${THEMEDIR}
	(cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THEMEDIR})

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
