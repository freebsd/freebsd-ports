# Created by: heiner Eichmann <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	manu-gothica
DISTVERSION=	0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.bryld.dk/filer/ \
		http://www.kswla.org/KATG%20Page%20Files/
DISTNAME=	manugot19
EXTRACT_SUFX=	.ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old German blackletter handwriting (Suetterlin)

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

RESTRICTED=	The font is free for personal use

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} manugot19.ttf \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/fonts/TTF
	@${LN} -sf ${DATADIR}/manugot19.ttf \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/TTF

.include <bsd.port.mk>
