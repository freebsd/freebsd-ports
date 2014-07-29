# Created by: netch@netch.kiev.ua
# $FreeBSD$

PORTNAME=	linuxfdisk
PORTVERSION=	2.11z
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.sunet.se/pub/Linux/kernel.org/linux/utils/util-linux/v2.11/ \
		http://ftp.be.debian.org/pub/linux/utils/util-linux/v2.11/ \
		ftp://segfault.kiev.ua/pub/
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	Fdisk, a partition tables manipulator, from util-linux

WRKSRC=		${WRKDIR}/util-linux-${PORTVERSION}/fdisk
USES=		tar:bzip2
ONLY_FOR_ARCHS=	i386 amd64

pre-patch:
	@rm -f ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-Makefile ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-sys_bsd.c ${WRKSRC}/sys_bsd.c

.include <bsd.port.mk>
