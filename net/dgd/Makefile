# New ports collection makefile for:	dgd
# Version required:	1.1
# Date created:		23 August 1994
# Whom:			adam
#
# $Id: Makefile,v 1.72 1997/04/15 23:25:08 adam Exp $
#

DISTNAME=	dgd-1.1p2
DISTFILES=	dgd-1.1.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/ \
		ftp://ftp.veda.is/pub/mud/dgd/ \
		ftp://ftp.dreamlabs.com/pub/mud/dgd/

PATCH_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/patches/ \
		ftp://ftp.veda.is/pub/mud/dgd/patches/ \
		ftp://ftp.dreamlabs.com/pub/mud/dgd/patches/
PATCHFILES=	1.1p1.gz \
		1.1p1-1.1p2.gz

MAINTAINER=	adam@veda.is

NO_CDROM=	"no distribution to corporate environment"
RESTRICTED=	"license required for commercial use"

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
