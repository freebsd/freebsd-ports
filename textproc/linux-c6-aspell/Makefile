# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	aspell
PORTVERSION=	0.60.6
DISTVERSIONSUFFIX=	-12.el6
PORTREVISION=	3
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Spelling checker with better logic than ispell (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL21+

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
