# $FreeBSD$

PORTNAME=	slim-freebsd-black-theme
DISTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	https://bitbucket.org/rigoletto-freebsd/slim-freebsd-black-theme/get/

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Simple FreeBSD SLiM theme inspired on the FreeBSD SLiM theme

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	montserrat>=0:x11-fonts/montserrat \
		slim>=0:x11/slim

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/rigoletto-freebsd-${PORTNAME}-d8bc075cbd32
PORTDOCS=	AUTHORS TRADEMARKS
SUB_FILES=	pkg-message

PLIST_FILES=	share/slim/themes/slim-freebsd-black-theme/background.png \
		share/slim/themes/slim-freebsd-black-theme/panel.png \
		share/slim/themes/slim-freebsd-black-theme/preview.png \
		share/slim/themes/slim-freebsd-black-theme/slim.theme

OPTIONS_DEFINE=	DOCS

THEMEDIR_REL=	share/slim/themes/slim-freebsd-black-theme
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
