# New ports collection makefile for:	dgd
# Version required:	1.0.37
# Date created:		23 August 1994
# Whom:			adam
#
# $Id: Makefile,v 1.49 1996/07/31 13:25:02 adam Exp $
#

DISTNAME=	dgd-1.0.63
DISTFILES=	dgd-1.0.37.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

PATCH_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/patches/ \
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
		1.0.62-1.0.63.gz

MAINTAINER=	adam@veda.is

NO_CDROM=	no distribution to corporate environment
RESTRICTED=	license required for commercial use

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
#PATCH_DIST_STRIP=	-p1

pre-patch:
	@for i in ${WRKSRC}/host/pc/res/*.ico; do \
		mv $$i $$i.bak; \
		echo '\ No newline at end of file' >$$i; \
		done
	@ln -sf ${WRKDIR}/dgd ${WRKSRC}

post-patch:
	@for i in ${WRKSRC}/host/pc/res/*.ico; do \
		rm $$i.orig; \
		mv $$i.bak $$i; \
		done

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@chmod o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-mv ${PREFIX}/dgd/bin/driver ${PREFIX}/dgd/bin/driver.old
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' ${PKGDIR}/PLIST` \
		| tar -C ${PREFIX} -xpf -

.include <bsd.port.mk>
