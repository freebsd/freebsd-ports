# New ports collection makefile for:	dgd-net
# Version required:	1.0.56
# Date created:		17 June 1996
# Whom:			adam
#
# $Id$
#

DISTNAME=	dgd-net-1.0.56
DISTFILES=	dgd-1.0.37.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

PATCH_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/patches/ \
		ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/pkg/
PATCHFILES=	1.0.37-1.0.39.gz \
		1.0.39-1.0.40.gz \
		1.0.40-1.0.56.gz \
		net-10.dgd-56.gz

MAINTAINER=	adam@veda.is

NO_CDROM=	no distribution to corporate environment
RESTRICTED=	license required for commercial use

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_DIST_STRIP=	-p1

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@mv ${WRKDIR}/dgd/bin/driver ${WRKDIR}/dgd/bin/driver.net
	@mv ${WRKDIR}/dgd/bin/precomp ${WRKDIR}/dgd/bin/precomp.net
	@mv ${WRKDIR}/dgd/doc/Introduction ${WRKDIR}/dgd/doc/Introduction.NET
	@mv ${WRKDIR}/dgd/doc/kfun/send_message ${WRKDIR}/dgd/doc/kfun/send_message.NET
	@chmod o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-mv ${PREFIX}/dgd/bin/driver.net ${PREFIX}/dgd/bin/driver.net.old
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' ${PKGDIR}/PLIST` \
		| tar -C ${PREFIX} -xpf -

.include <bsd.port.mk>
