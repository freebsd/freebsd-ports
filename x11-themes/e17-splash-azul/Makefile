# New ports collection makefile for:	e17-splash-azul
# Date created:		4 Aug 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	azul
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www0.get-e.org/Themes/Startup/_files/ \
		http://sunner.elcomnet.ru/~stas/
PKGNAMEPREFIX=	e17-splash-
DISTNAME=	init_azul
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Azul splash screen for e17 window manager

RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/init/init_azul.edj

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/init
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/init

.include <bsd.port.mk>
