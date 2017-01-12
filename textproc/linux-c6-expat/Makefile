# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux/i386 binary port of Expat XML-parsing library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-expat-[0-9]* linux-f8-expat-[0-9]* linux-f10-expat-[0-9]*

RPMVERSION=	13.el6_8
USES=		linux:c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

PORTDOCS=	COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

.include <bsd.port.mk>
