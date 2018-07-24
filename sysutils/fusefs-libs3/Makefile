# Created by: Stefan Esser
# $FreeBSD$

PORTNAME=	fusefs-libs3
DISTVERSIONPREFIX=	fuse-
DISTVERSION=	3.2.5
CATEGORIES=	sysutils

MAINTAINER=	se@freebsd.org
COMMENT=	FUSE library version 3 for filesystems implemented in userspace

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BROKEN_mips=		fails to compile: unrecognized command line option "-Wno-unused-result"
BROKEN_mips64=		fails to compile: unrecognized command line option "-Wno-unused-result"
BROKEN_powerpc64=	fails to compile: unrecognized command line option "-Wno-unused-result"

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
