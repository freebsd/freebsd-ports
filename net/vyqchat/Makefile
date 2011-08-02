# New ports collection makefile for:	vyqchat
# Date created:				25 August 2005
# Whom:					vic_semionov
#
# $FreeBSD$
#

PORTNAME=	vyqchat
PORTVERSION=	0.2.9
CATEGORIES=	net
MASTER_SITES=	http://www.linux-projects.net/d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Qt LAN chat, compatible with Vypress Chat

BROKEN=		unfetchable

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-09-01

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-Qt-dir=${QT_PREFIX}

QTCFGLIBS=	${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ARTS)
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/arts
.else
CONFIGURE_ARGS+=--without-arts
.endif

.if defined(WITH_LIBAO)
LIB_DEPENDS+=	ao:${PORTSDIR}/audio/libao
.else
CONFIGURE_ARGS+=--without-libao
.endif

.if !defined(WITHOUT_ARTS) || defined(WITH_LIBAO)
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.endif

.include <bsd.port.post.mk>
