# $FreeBSD$

PORTNAME=	freetype
PORTVERSION=	2.8
DISTVERSIONSUFFIX=	-14.el7_9.1
PORTREVISION=	2
CATEGORIES=	print linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Font rendering engine (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	png
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
