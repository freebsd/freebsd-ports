# New ports collection makefile for:	dgd
# Version required:	1.0.91
# Date created:		23 August 1994
# Whom:			adam
#
# $Id: Makefile,v 1.56 1996/11/06 16:45:39 adam Exp $
#

DISTNAME=	dgd-1.0.91
DISTFILES=	dgd-1.0.91.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

#PATCH_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/patches/ \
#		ftp.veda.is:/pub/mud/dgd/patches/
#PATCHFILES=	1.0.91-1.0.92.gz

MAINTAINER=	adam@veda.is

NO_CDROM=	no distribution to corporate environment
RESTRICTED=	license required for commercial use

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@chmod o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-mv ${PREFIX}/dgd/bin/driver ${PREFIX}/dgd/bin/driver.old
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' ${PKGDIR}/PLIST` \
		| tar -C ${PREFIX} -xpf -

.include <bsd.port.mk>
