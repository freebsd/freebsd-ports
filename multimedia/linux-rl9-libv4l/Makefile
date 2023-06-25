PORTNAME=	libv4l
PORTVERSION=	1.20.0
DISTVERSIONSUFFIX=	-5.el9
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Video4Linux library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://linuxtv.org/wiki/index.php/V4l-utils

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

SRC_DISTFILES=	v4l-utils-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
