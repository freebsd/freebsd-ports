PORTNAME=	hwdata
DISTVERSIONPREFIX=	v
DISTVERSION=	0.397
PORTEPOCH=	1
CATEGORIES=	misc

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Database of IDs used in PCI, PNP and USB devices
WWW=		https://github.com/vcrhonek/hwdata

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	ginstall:sysutils/coreutils

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	vcrhonek
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datarootdir=${PREFIX}/share

BINARY_ALIAS=	install=ginstall

NO_ARCH=	yes

.include <bsd.port.mk>
