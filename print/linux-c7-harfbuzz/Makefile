# $FreeBSD$

PORTNAME=	harfbuzz
PORTVERSION=	1.7.5
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	print linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenType text shaping engine (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	graphite2
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
