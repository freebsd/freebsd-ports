# New ports collection makefile for:	fsck_ext2fs
# Date Created:				16 Jul 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fsck_ext2fs
PORTVERSION=	2.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ext2fs filesystem consistency check and interactive repair

MAN8=		fsck_ext2fs.8
PLIST_FILES=	sbin/fsck_ext2fs

do-build:
	@cd ${WRKSRC}/fsck_ext2fs && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsck_ext2fs/fsck_ext2fs ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/fsck_ext2fs/fsck_ext2fs.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
