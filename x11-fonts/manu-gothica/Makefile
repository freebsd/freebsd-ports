# Created by: heiner Eichmann <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	manu-gothica
DISTVERSION=	0
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.bryld.dk/filer/ \
		http://www.kswla.org/KATG%20Page%20Files/
DISTNAME=	manugot19
EXTRACT_SUFX=	.ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old German blackletter handwriting (Suetterlin)

USES=		fonts

RESTRICTED=	The font is free for personal use

FONTNAME=	TTF
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
PLIST_FILES=	${FONTSDIR}/manugot19.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} manugot19.ttf \
		${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
