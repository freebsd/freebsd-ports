# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	plank-theme-moka
PORTVERSION=	20140709
CATEGORIES=	x11-themes
MASTER_SITES=	http://mokaproject.com/packages/zip/
DISTNAME=	${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Moka Plank theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	plank:x11-wm/plank

USES=	zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/plank/themes
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} Moka \
		${STAGEDIR}${PREFIX}/share/plank/themes

.include <bsd.port.mk>
