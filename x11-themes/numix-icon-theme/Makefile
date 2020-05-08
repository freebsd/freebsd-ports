# $FreeBSD$

PORTNAME=	numix-icon-theme
PORTVERSION=	20.03.20
CATEGORIES=	x11-themes

MAINTAINER=	20.100@defert.com
COMMENT=	Official base icon theme from the Numix Project

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/license

USES=		gnome

USE_GITHUB=	yes
GH_ACCOUNT=	numixproject

INSTALLS_ICONS=	yes

NO_ARCH=	yes
NO_BUILD=	yes

ICONSDIR=	${PREFIX}/share/icons

do-install:
	${MKDIR} ${STAGEDIR}${ICONSDIR}
	${FIND} ${WRKSRC} -mindepth 1 -maxdepth 1 -type d -exec ${CP} -R {} \
		${STAGEDIR}${ICONSDIR}/ ';'

.include <bsd.port.mk>
