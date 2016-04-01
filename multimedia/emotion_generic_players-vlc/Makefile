# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vlc
PORTVERSION=	1.16.0
CATEGORIES=	multimedia enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PKGNAMEPREFIX:S/-//}/
PKGNAMEPREFIX=	emotion_generic_players-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Additional loader for Emotion (vlc)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl \
		libvlc.so:multimedia/vlc

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:xz
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-profile=release

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R}

.include <bsd.port.mk>
