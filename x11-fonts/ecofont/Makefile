# Created by: Joseph S. Atkinson <jsa@wickedmachine.net>
# $FreeBSD$

PORTNAME=	ecofont
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.ecofont.com/assets/files/
DISTNAME=	ecofont_vera_sans_regular

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Environmentally friendly, ink saving typeface

LICENSE=	NONE

BROKEN=		unfetchable
DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

USES=		fonts zip
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${FONTSDIR}/${ECOFONT}

SUB_FILES=	pkg-message

ECOFONT=	${DISTNAME}.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/${ECOFONT} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
