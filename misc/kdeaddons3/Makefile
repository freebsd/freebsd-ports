# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	2.2.1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org

USE_KDEBASE_VER=2
LIB_DEPENDS+=	noatun.0:${PORTSDIR}/audio/kdemultimedia2
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB+=	RM=${RM}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/SDL11/SDL.h)
WITH_SDL=	yes
.endif

.if defined(WITH_SDL) && ${WITH_SDL} == yes
LIB_DEPENDS+=	SDL-1.1.3:${PORTSDIR}/devel/sdl12
CONFIGURE_ENV+=	SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with SDL support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SDL=yes\""
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
