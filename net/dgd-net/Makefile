# New ports collection makefile for:	dgd-net
# Version required:	1.0.91
# Date created:		17 June 1996
# Whom:			adam
#
# $Id: Makefile,v 1.12 1996/11/06 17:00:46 adam Exp $
#

DISTNAME=	dgd-net-1.0.93
DISTFILES=	dgd-1.0.91.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

PATCH_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/patches/ \
		ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/pkg/ \
		ftp.veda.is:/pub/mud/dgd/patches/
PATCHFILES=	1.0.91-1.0.92.gz \
		1.0.92-1.0.93.gz \
		net-10.dgd-91.gz

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
