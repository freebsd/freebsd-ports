PORTNAME=	unclutter-xfixes
PORTVERSION=	1.6
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Rewrite of unclutter using the x11-xfixes extension
WWW=		https://github.com/Airblader/unclutter-xfixes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libev.so:devel/libev

USES=		gmake pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	Airblader

USE_XORG=	x11 xi xfixes

CONFLICTS_INSTALL=	unclutter-8*

PLIST_FILES=	bin/unclutter \
		share/man/man1/unclutter.1.gz

MAKE_ARGS=	CC=${CC}

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
