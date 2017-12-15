# Created by: Stefan Esser
# $FreeBSD$

PORTNAME=	fusefs-libs3
DISTVERSIONPREFIX=	fuse-
DISTVERSION=	3.2.1
CATEGORIES=	sysutils

MAINTAINER=	se@freebsd.org
COMMENT=	FUSE library version 3 for filesystems implemented in userspace

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libfuse
GH_PROJECT=	libfuse

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
IGNORE=	fusefs has not been implemented on DragonFly
.endif

.include <bsd.port.post.mk>
