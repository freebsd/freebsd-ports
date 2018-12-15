# Created by: Oleh Hushchenkov <gor@clogic.com.ua>
# $FreeBSD$

PORTNAME=	unclutter-xfixes
PORTVERSION=	1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Rewrite of unclutter using the x11-xfixes extension

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libev.so:devel/libev

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Airblader

USE_XORG=	x11 xi xfixes

CONFLICTS_INSTALL=	unclutter-8*

PLIST_FILES=	bin/unclutter \
		man/man1/unclutter.1.gz

MAKE_ENV+=	UNCLUTTER_VERSION=${PORTVERSION}
MAKE_ARGS=	CC=${CC}

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
