# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	aspell
PORTVERSION=	0.60.6
PORTREVISION=	1
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Spelling checker with better logic than ispell (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-aspell-[0-9]* linux-f10-aspell-[0-9]*

USES=		linux:c6
USE_LINUX_RPM=	yes

RPMVERSION=	12.el6
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
