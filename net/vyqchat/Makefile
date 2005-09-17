# New ports collection makefile for:	vyqchat
# Date created:				25 August 2005
# Whom:					vic_semionov
#
# $FreeBSD$
#

PORTNAME=	vyqchat
PORTVERSION=	0.2.8
CATEGORIES=	net
MASTER_SITES=	http://linux.bydg.org/~yogin/

MAINTAINER=	semionov@mail.bg
COMMENT=	A Qt LAN chat, compatible with Vypress Chat

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
QTCFGLIBS=	${PTHREAD_LIBS}

CONFIGURE_ARGS=	--with-Qt-dir=${QT_PREFIX}

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
