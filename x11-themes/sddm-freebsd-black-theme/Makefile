PORTNAME=	sddm-freebsd-black-theme
DISTVERSION=	1.3
CATEGORIES=	x11-themes
MASTER_SITES=	https://bitbucket.org/rigoletto-freebsd/sddm-freebsd-black-theme/get/

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Simple SDDM theme inspired on the FBSD SLiM theme

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	montserrat>=0:x11-fonts/montserrat

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/rigoletto-freebsd-${PORTNAME}-f874b7e976e4
PORTDOCS=	AUTHORS CHANGELOG TRADEMARKS
PLIST_SUB=      THEMEDIR=${THEMEDIR_REL}
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
