# New ports collection makefile for:    wingz
# Version required:	142
# Date created:         Wed Nov 27 09:15:10 CST 1996
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.5 1998/08/05 09:31:29 asami Exp $
#

DISTNAME=	Wingz-142
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/spreadsheet
EXTRACT_SUFX=	.tgz

MANINAINER=	erich@FreeBSD.org

RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes

USE_X_PREFIX=	yes

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
