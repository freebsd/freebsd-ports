# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.1.6
CATEGORIES=	net lang
MASTER_SITES=	ftp://ftp.imaginary.com/pub/LPC/servers/DGD/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/ \
		ftp://ftp.veda.is/pub/mud/dgd/ \
		ftp://ftp.dreamlabs.com/pub/mud/dgd/
DISTNAME=	dgd-1.1

PATCH_SITES=	ftp://ftp.imaginary.com/pub/LPC/servers/DGD/patches/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/patches/ \
		ftp://ftp.veda.is/pub/mud/dgd/patches/ \
		ftp://ftp.dreamlabs.com/pub/mud/dgd/patches/
PATCHFILES=	1.1p1.gz \
		1.1p2.gz \
		1.1p3.gz \
		1.1p4.gz \
		1.1p5.gz \
		1.1p6.gz

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
	@${CHMOD} o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-${MV} ${PREFIX}/dgd/bin/driver ${PREFIX}/dgd/bin/driver.old
	@tar -C ${WRKDIR} -cf - `${GREP} '^dgd/' ${PLIST}` \
		| tar -C ${PREFIX} -xpf -

.include <bsd.port.mk>
