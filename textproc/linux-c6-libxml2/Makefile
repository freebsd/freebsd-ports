# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libxml2
PORTVERSION=	2.7.6
PORTREVISION=	9
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library providing XML and HTML support (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-libxml2-[0-9]*

USES=		linux:c6
USE_LINUX_RPM=	yes

RPMVERSION=	21.el6_8.1
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog.gz Copyright NEWS README TODO

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
