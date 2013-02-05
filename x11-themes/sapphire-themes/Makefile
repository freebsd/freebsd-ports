# Created by: trevor
# $FreeBSD$

PORTNAME=	sapphire-themes
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11-themes x11-wm
MASTER_SITES=	http://jpj.net/~trevor/${PORTNAME}/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for sapphire

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

BROKEN=		depends on conflicting packages (xli and xloadimage both installs bin/xsetbg)

RUN_DEPENDS=	xli:${PORTSDIR}/graphics/xli \
		xloadimage:${PORTSDIR}/x11/xloadimage \
		sapphire:${PORTSDIR}/x11-wm/sapphire

REINPLACE_ARGS=	-i '' -E

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-patch:
	${REINPLACE_CMD} 's:~/\.:${LOCALBASE}/share/:g' \
		${WRKDIR}/menu/default \
		${WRKDIR}/themes/*.theme
	${REINPLACE_CMD} 's:-15-:-12-:g' ${WRKDIR}/themes/*.theme

do-install:
	${MKDIR} ${LOCALBASE}/share/sapphire/themes/backgrounds/
	${INSTALL_DATA} ${WRKDIR}/themes/backgrounds/* \
		${LOCALBASE}/share/sapphire/themes/backgrounds/
	${INSTALL_DATA} ${WRKDIR}/themes/*.theme \
		${LOCALBASE}/share/sapphire/themes/
	${INSTALL_DATA} ${WRKDIR}/menu/default ${LOCALBASE}/share/sapphire/menu/

.include <bsd.port.mk>
