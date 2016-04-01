# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rage
PORTVERSION=	0.1.4
CATEGORIES=	multimedia enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	EFL video and audio player with some extra bells and whistles

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl \
		libelementary.so:x11-toolkits/elementary

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		desktop-file-utils pkgconfig tar:xz

.include <bsd.port.mk>
