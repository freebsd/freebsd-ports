# New ports collection makefile for:	padauk
# Date created:		July 30 2010
# Whom:			Kuan-Chung Chiu <buganini@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	padauk
PORTVERSION=	2.6.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://security-hole.info/distfile/
DISTNAME=	ttf-sil-padauk-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Unicode font supporting all the Myanmar characters

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes

NO_WRKSUBDIR=	yes
FONTSDIR=	lib/X11/fonts/Myanmar/
PLIST_SUB+=	FONTSDIR=${FONTSDIR}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_MSG} "==> Running fc-cache"
	@-${LOCALBASE}/bin/fc-cache -f -v ${PREFIX}/${FONTSDIR}

.include <bsd.port.mk>
