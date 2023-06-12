PORTNAME=	freetype
PORTVERSION=	2.10.4
DISTVERSIONSUFFIX=	-9.el9
CATEGORIES=	print linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Font rendering engine (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.freetype.org/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	png
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
