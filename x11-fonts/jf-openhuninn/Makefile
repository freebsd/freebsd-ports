# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jf-openhuninn
PORTVERSION=	1.0
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jf Open Huninn by justfont

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/SIL_Open_Font_License_1.1.txt

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/jf-openhuninn-${PORTVERSION}.ttf

USE_GITHUB=	yes
GH_ACCOUNT=	justfont
GH_PROJECT=	open-huninn-font
GH_TAGNAME=	4b186c5

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/font/jf-openhuninn-${PORTVERSION}.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
