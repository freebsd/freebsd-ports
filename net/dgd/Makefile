# New ports collection makefile for:	dgd
# Version required:	1.0.37
# Date created:		23 August 1994
# Whom:			adam
#
# $Id: Makefile,v 1.46 1996/06/17 01:04:10 asami Exp $
#

DISTNAME=	dgd-1.0.56
DISTFILES=	dgd-1.0.37.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

PATCH_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/patches/
PATCHFILES=	1.0.37-1.0.39.gz \
		1.0.39-1.0.40.gz \
		1.0.40-1.0.56.gz

MAINTAINER=	adam@veda.is

NO_CDROM=	no distribution to corporate environment
RESTRICTED=	license required for commercial use

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_DIST_STRIP=	-p1

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@chmod o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-mv ${PREFIX}/dgd/bin/driver ${PREFIX}/dgd/bin/driver.old
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' ${PKGDIR}/PLIST` \
		| tar -C ${PREFIX} -xpf -

.include <bsd.port.mk>
