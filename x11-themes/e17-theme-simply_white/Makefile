# New ports collection makefile for:	e17-theme-simply_white
# Date created:		5 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	simply_white
PORTVERSION=	0.6
CATEGORIES=	x11-themes
MASTER_SITES=	http://www0.get-e.org/Themes/E17/_files/ \
		ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-theme-
DISTNAME=	simply-white
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Simply White theme for use with e17 window manager

RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/themes/${DISTNAME}${EXTRACT_SUFX}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/themes
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/themes

.include <bsd.port.mk>
