PORTNAME=	rage
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	multimedia enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	EFL video and audio player with some extra bells and whistles
WWW=		https://www.enlightenment.org/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl

DIST_SUBDIR=	enlightenment
USES=		compiler:c11 desktop-file-utils meson pkgconfig tar:xz

CONFLICTS=	rage-encryption

.include <bsd.port.mk>
