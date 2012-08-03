# New ports collection makefile for:	fusefs-ext4fuse
# Date created:				12 Nov 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ext4fuse
PORTVERSION=	20120803
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	EXT4 implementation for FUSE

LICENSE=	GPLv2

BUILD_DEPENDS=	fusefs-libs>=2.7.2:${PORTSDIR}/sysutils/fusefs-libs
LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		execinfo.1:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_GMAKE=	yes
USE_PKGCONFIG=	build

MAKE_JOBS_SAFE=	yes

# explicitly empty to fix a cross compiling related issue (PR: 165480)
MAKE_ENV+=	TARGET_ARCH=

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/ext4fuse

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
