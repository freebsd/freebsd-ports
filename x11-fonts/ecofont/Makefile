# New ports collection makefile for:	ecofont
# Date created:		2010-04-09
# Whom:			Joseph S. Atkinson <jsa@wickedmachine.net>
#
# $FreeBSD$
#

PORTNAME=	ecofont
PORTVERSION=	2.05
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.ecofont.com/assets/files/
DISTNAME=	ecofont_vera_sans_regular

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Environmentally friendly, ink saving typeface

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	${ECOFONTDIR}/${ECOFONT}
PLIST_DIRS=	${ECOFONTDIR}

SUB_LIST=	ECOFONTDIR="${PREFIX}/${ECOFONTDIR}"
SUB_FILES=	pkg-message

ECOFONT=	${DISTNAME}.ttf
ECOFONTDIR=	lib/X11/fonts/${PORTNAME}

do-install:
	@${MKDIR} ${PREFIX}/${ECOFONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/${ECOFONT} ${PREFIX}/${ECOFONTDIR}

post-install:
	@${LOCALBASE}/bin/fc-cache -f -v ${PREFIX}/${ECOFONTDIR} > /dev/null
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
