# New ports collection makefile for:	kde4-xdg-env
# Date created:		2008-06-30
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	xdg
PORTVERSION=	1.0.1
CATEGORIES=	misc kde
MASTER_SITES=	# none
PKGNAMEPREFIX=	kde4-
PKGNAMESUFFIX=	-env
DISTNAME=	# none
EXTRACT_SUFX=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Script which hooks into startkde and helps KDE pick up XDG apps/menus

USE_KDE4=	kdeprefix

SUB_LIST+=	KDE4_PREFIX=${KDE4_PREFIX}

NO_BUILD=	yes

SUB_FILES=	xdg-env.sh

PLIST_FILES=	env/xdg-env.sh
PLIST_DIRSTRY=	env

do-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/xdg-env.sh ${PREFIX}/env

.include <bsd.port.mk>
