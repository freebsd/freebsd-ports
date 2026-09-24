PORTNAME=	harfbuzz-icu
PORTVERSION=	2.7.4
DISTVERSIONSUFFIX=	-10.el9
CATEGORIES=	print linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ICU support for HarfBuzz (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://harfbuzz.github.io/

LICENSE=	MIT

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	harfbuzz icu
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

SRC_DISTFILES=	harfbuzz-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

DESCR=		${PORTSDIR}/${PKGCATEGORY}/harfbuzz/pkg-descr

.include <bsd.port.mk>
