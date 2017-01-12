# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-libssh2-[0-9]*

RPMVERSION=	2.el6_7.1
USES=		linux:c6
USE_LINUX=	openssl

USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
