# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	b612
PORTVERSION=	1.005
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Highly legible font family for aircraft cockpit screens

LICENSE=	EDL EPL OFL11
LICENSE_COMB=	dual
LICENSE_NAME_EDL=	Eclipse Distribution License
LICENSE_FILE_EDL=	${WRKSRC}/edl-v10.html
LICENSE_FILE_EPL=	${WRKSRC}/epl-v10.html
LICENSE_PERMS_EDL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

FONTNAME=	b612

GH_ACCOUNT=	polarsys
GH_TAGNAME=	97aa715
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
