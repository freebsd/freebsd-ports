PORTNAME=	libfprint
PORTVERSION=	1.94.8
DISTVERSIONPREFIX=v
PORTREVISION=	0
CATEGORIES=	security
WWW=		https://gitlab.freedesktop.org/libfprint/libfprint/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fingerprint reader devices
WWW=		https://www.freedesktop.org/wiki/Software/fprint/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnss3.so:security/nss \
		libnspr4.so:devel/nspr  \
		libudev.so:devel/libudev-devd

MESON_ARGS= 	-Dudev_rules=disabled -Dudev_hwdb=disabled

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	libfprint

USES=		meson pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
