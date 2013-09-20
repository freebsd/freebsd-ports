# Created by: Jeremy Chadwick <freebsd@jdc.parodius.com>
# $FreeBSD$

PORTNAME=	mcelog
DISTVERSION=	1.0pre3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.kernel.org/pub/linux/utils/cpu/mce/ \
		http://147.52.159.12/mirrors/ftp.kernel.org/pub/linux/utils/cpu/mce/ \
		http://ftp.sjtu.edu.cn/sites/ftp.kernel.org/pub/linux/utils/cpu/mce/ \
		http://mirror.be.gbxs.net/pub/linux/utils/cpu/mce/ \
		http://ftp.eu.openbsd.org/pub/linux/utils/cpu/mce/ \
		http://korg.cs.utah.edu/pub/linux/utils/cpu/mce/ \
		http://ftp.oregonstate.edu/pub/linux/utils/cpu/mce/

MAINTAINER=	jdc@koitsu.org
COMMENT=	Collects and decodes Machine Check Exception data

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 ia64

PATCH_STRIP=	-p1

USE_GMAKE=	yes
MAKE_ENV+=	FREEBSD=1
LDFLAGS=	-lkvm

PLIST_FILES=	bin/mcelog
MAN8=		mcelog.8

NO_STAGE=	yes
post-patch:
	@${CP} ${FILESDIR}/memstream.c ${WRKSRC}/memstream.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcelog ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mcelog.8 ${MAN8PREFIX}/man/man8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
