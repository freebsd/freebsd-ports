# New ports collection makefile for:	linuxfdisk
# Date created:		Mon Jun 16 14:52:38 UTC 2003
# Whom:			netch@netch.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	linuxfdisk
PORTVERSION=	2.11z
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.kernel.org/pub/linux/utils/util-linux/
DISTNAME=	util-linux-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	Fdisk, a partition tables manipulator, from util-linux

WRKSRC=		${WRKDIR}/linuxfdisk-${PORTVERSION}
USE_BZIP2=	yes
MAN8=		linuxfdisk.8

post-extract:
	@cd ${WRKDIR} && ${LN} -sf util-linux-${PORTVERSION}/fdisk linuxfdisk-${PORTVERSION}

pre-patch:
	@rm -f ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-Makefile ${WRKSRC}/Makefile
	@cp ${FILESDIR}/linuxfdisk-sys_bsd.c ${WRKSRC}/sys_bsd.c
	@cp -p ${WRKSRC}/fdisk.8 ${WRKSRC}/linuxfdisk.8

.include <bsd.port.mk>
