# New ports collection makefile for:	dgd-net
# Version required:	1.0.86
# Date created:		17 June 1996
# Whom:			adam
#
# $Id: Makefile,v 1.10 1996/10/30 00:23:44 adam Exp $
#

DISTNAME=	dgd-net-1.0.86
DISTFILES=	dgd-1.0.37.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

PATCH_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/patches/ \
		ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/pkg/ \
		ftp.veda.is:/pub/mud/dgd/patches/
PATCHFILES=	1.0.37-1.0.39.gz \
		1.0.39-1.0.40.gz \
		1.0.40-1.0.56.gz \
		1.0.56-1.0.57.gz \
		1.0.57-1.0.58.gz \
		1.0.58-1.0.59.gz \
		1.0.59-1.0.60.gz \
		1.0.60-1.0.61.gz \
		1.0.61-1.0.62.gz \
		1.0.62-1.0.63.gz \
		1.0.63-1.0.64.gz \
		1.0.64-1.0.65.gz \
		1.0.65-1.0.66.gz \
		1.0.66-1.0.67.gz \
		1.0.67-1.0.68.gz \
		1.0.68-1.0.69.gz \
		1.0.69-1.0.70.gz \
		1.0.70-1.0.71.gz \
		1.0.71-1.0.72.gz \
		1.0.72-1.0.73.gz \
		1.0.73-1.0.74.gz \
		1.0.74-1.0.75.gz \
		1.0.75-1.0.76.gz \
		1.0.76-1.0.77.gz \
		1.0.77-1.0.78.gz \
		1.0.78-1.0.79.gz \
		1.0.79-1.0.80.gz \
		1.0.80-1.0.81.gz \
		1.0.81-1.0.82.gz \
		1.0.82-1.0.83.gz \
		1.0.83-1.0.84.gz \
		1.0.84-1.0.85.gz \
		1.0.85-1.0.86.gz \
		net-10.dgd-86.gz \
		1.0.86-1.0.87.gz \
		1.0.87-1.0.88.gz \
		1.0.88-1.0.89.gz \
		1.0.89-1.0.90.gz

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

pre-patch:
	@for i in ${WRKSRC}/host/pc/res/*.ico; do \
		mv $$i $$i.bak; \
		echo '\ No newline at end of file' >$$i; \
		done

post-patch:
	@for i in ${WRKSRC}/host/pc/res/*.ico; do \
		rm $$i.orig; \
		mv $$i.bak $$i; \
		done

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
