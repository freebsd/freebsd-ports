# New ports collection makefile for:	vyqchat
# Date created:				25 August 2005
# Whom:					vic_semionov
#
# $FreeBSD$
#

PORTNAME=	vyqchat
PORTVERSION=	0.2.8
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://linux.bydg.org/~yogin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Qt LAN chat, compatible with Vypress Chat

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

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

.if !defined(WITHOUT_ARTS) || defined(WITH_LIBAO)
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,Settings::getUUID,getUUID,' \
		${WRKSRC}/src/settings.h
	@${REINPLACE_CMD} -e 's,Sound::error,error,' \
		${WRKSRC}/src/sound.h
	@${REINPLACE_CMD} -e 's,User::setStatus,setStatus,' \
		${WRKSRC}/src/user.h

.include <bsd.port.post.mk>
