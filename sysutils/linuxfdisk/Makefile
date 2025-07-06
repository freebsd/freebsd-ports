PORTNAME=	linuxfdisk
PORTVERSION=	2.11z
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/utils/util-linux/v2.11/ \
		http://ftp.be.debian.org/pub/linux/utils/util-linux/v2.11/ \
		ftp://segfault.kiev.ua/pub/
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	Fdisk, a partition tables manipulator, from util-linux

DEPRECATED=	This port is way out of date, use devel/util-linux instead
EXPIRATION_DATE=2025-09-30

LICENSE=	GPLv2+

BROKEN_aarch64=	fails to build: error unknown architecture

WRKSRC=		${WRKDIR}/util-linux-${PORTVERSION}/fdisk
USES=		tar:bzip2

pre-patch:
	@${CP} ${FILESDIR}/linuxfdisk-Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/linuxfdisk-sys_bsd.c ${WRKSRC}/sys_bsd.c

.include <bsd.port.mk>
