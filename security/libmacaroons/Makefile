PORTNAME=	libmacaroons
DISTVERSION=	0.3.0-20210219
CATEGORIES=	security devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible authorization credentials library
WWW=		https://github.com/rescrv/libmacaroons

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rescrv
GH_TAGNAME=	ca0211d

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/macaroons.h \
		lib/libmacaroons.a \
		lib/libmacaroons.so \
		lib/libmacaroons.so.0 \
		lib/libmacaroons.so.0.0.1 \
		libdata/pkgconfig/libmacaroons.pc

.include <bsd.port.mk>
