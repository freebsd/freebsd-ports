# New ports collection makefile for:    wingz
# Version required:	142
# Date created:         Wed Nov 27 09:15:10 CST 1996
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

DISTNAME=	Wingz-142
CATEGORIES=	math linux
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/spreadsheet
EXTRACT_SUFX=	.tgz

MAINTAINER=	erich@FreeBSD.org

RUN_DEPENDS=    /compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes

USE_X_PREFIX=	yes

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
