# Created by: Joseph S. Atkinson <jsa@wickedmachine.net>
# $FreeBSD$

PORTNAME=	ecofont
PORTVERSION=	2.05
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.ecofont.com/assets/files/
DISTNAME=	ecofont_vera_sans_regular

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Environmentally friendly, ink saving typeface

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		zip
NO_BUILD=	yes

PLIST_FILES=	${ECOFONTDIR}/${ECOFONT}
PLIST_DIRS=	${ECOFONTDIR}

SUB_LIST=	ECOFONTDIR="${PREFIX}/${ECOFONTDIR}"
SUB_FILES=	pkg-message

ECOFONT=	${DISTNAME}.ttf
ECOFONTDIR=	lib/X11/fonts/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ECOFONTDIR}
	${INSTALL_DATA} ${WRKDIR}/${ECOFONT} ${STAGEDIR}${PREFIX}/${ECOFONTDIR}

.include <bsd.port.mk>
