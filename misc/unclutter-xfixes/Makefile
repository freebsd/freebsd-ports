# Created by: Oleg Gushchenkov <gor@clogic.com.ua>
# $FreeBSD$

PORTNAME=	unclutter-xfixes
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	gor@clogic.com.ua
COMMENT=	Rewrite of unclutter using the x11-xfixes extension

LICENSE=	MIT

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libev.so:devel/libev

CONFLICTS_INSTALL=	unclutter-8*

CFLAGS+=	-I${LOCALBASE}/include

USE_GITHUB=	yes
GH_ACCOUNT=	Airblader

USE_XORG=	x11 xi xfixes

USES=		gmake pkgconfig

PLIST_FILES=	bin/unclutter \
		man/man1/unclutter.1.gz

MAKE_ENV+=	UNCLUTTER_VERSION=${PORTVERSION}
MAKE_ARGS=	CC=${CC}

.include <bsd.port.mk>
