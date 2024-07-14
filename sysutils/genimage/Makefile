PORTNAME=	genimage
DISTVERSIONPREFIX=	v
DISTVERSION=	18
#MASTER_SITES=	https://github.com/pengutronix/genimage/releases/download/v${DISTVERSION}/
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to generate multiple filesystem and flash images from a tree
WWW=		https://github.com/pengutronix/genimage

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USES=		autoreconf gettext-runtime pkgconfig #tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	pengutronix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

PLIST_FILES=	bin/genimage

.include <bsd.port.mk>
