# New ports collection makefile for:    wingz
# Version required:	142
# Date created:         Wed Nov 27 09:15:10 CST 1996
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.1.1.1 1996/12/04 20:05:12 erich Exp $
#

DISTNAME=	Wingz-142
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial
EXTRACT_SUFX=	.tgz

MANINAINER=	erich@FreeBSD.org

RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_WRKSUBDIR=	yes

USE_X11=	yes

post-install:
	@/bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
