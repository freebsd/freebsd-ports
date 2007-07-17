# New ports collection makefile for:	kde-xdg-env
# Date created:				April 03 2005
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xdg
PORTVERSION=	1.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	misc kde
MASTER_SITES=	# none
PKGNAMEPREFIX=	kde-
PKGNAMESUFFIX=	-env
DISTNAME=	# none
EXTRACT_SUFX=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Script which hooks into startkde and helps KDE pick up XDG apps/menus

.if defined(KDE_PREFIX)
PREFIX=		${KDE_PREFIX}
SUB_LIST+=	KDE_PREFIX=${KDE_PREFIX}
.else
SUB_LIST+=	KDE_PREFIX=${LOCALBASE}
.endif

NO_BUILD=	yes

SUB_FILES=	xdg-env.sh

PLIST_FILES=	env/xdg-env.sh
PLIST_DIRS=	env

do-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/xdg-env.sh ${PREFIX}/env

.include <bsd.port.mk>
