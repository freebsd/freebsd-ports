# Created by: netch@netch.kiev.ua
# $FreeBSD$

PORTNAME=	linuxfdisk
PORTVERSION=	2.11z
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.sunet.se/pub/Linux/kernel.org/linux/utils/util-linux/v2.11/ \
		http://ftp.be.debian.org/pub/linux/utils/util-linux/v2.11/ \
		ftp://segfault.kiev.ua/pub/
DISTNAME=	util-linux-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	Fdisk, a partition tables manipulator, from util-linux

WRKSRC=		${WRKDIR}/util-linux-${PORTVERSION}/fdisk
USE_BZIP2=	yes
MAN8=		fdisk-linux.8 cfdisk-linux.8 sfdisk-linux.8
ONLY_FOR_ARCHS=	i386 amd64

NO_STAGE=	yes
pre-patch:
	@rm -f ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-Makefile ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-sys_bsd.c ${WRKSRC}/sys_bsd.c

.include <bsd.port.mk>
