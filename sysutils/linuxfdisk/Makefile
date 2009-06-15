# New ports collection makefile for:	linuxfdisk
# Date created:		Mon Jun 16 14:52:38 UTC 2003
# Whom:			netch@netch.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	linuxfdisk
PORTVERSION=	2.11z
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG} \
		ftp://segfault.kiev.ua/pub/
MASTER_SITE_SUBDIR=	linux/utils/util-linux/old
DISTNAME=	util-linux-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	Fdisk, a partition tables manipulator, from util-linux

WRKSRC=		${WRKDIR}/util-linux-${PORTVERSION}/fdisk
USE_BZIP2=	yes
MAN8=		fdisk-linux.8 cfdisk-linux.8 sfdisk-linux.8
ONLY_FOR_ARCHS=	i386 amd64

pre-patch:
	@rm -f ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-Makefile ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-sys_bsd.c ${WRKSRC}/sys_bsd.c

.include <bsd.port.mk>
