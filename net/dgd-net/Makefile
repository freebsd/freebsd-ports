# New ports collection makefile for:	dgd-net
# Date created:		17 June 1996
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	dgd-net
PORTVERSION=	1.1.6
CATEGORIES=	net lang
MASTER_SITES=	ftp://ftp.imaginary.com/pub/LPC/servers/DGD/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/ \
		ftp://ftp.veda.is/pub/mud/dgd/ \
		ftp://ftp.dreamlabs.com/pub/mud/dgd/
DISTFILES=	dgd-1.1.tar.gz

PATCH_SITES=	ftp://ftp.imaginary.com/pub/LPC/servers/DGD/patches/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/patches/ \
		ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/pkg/ \
		ftp://ftp.veda.is/pub/mud/dgd/patches/ \
		ftp://ftp.dreamlabs.com/pub/mud/dgd/patches/
PATCHFILES=	net-10.dgd-1.1.gz \
		1.1p1.gz \
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

pre-patch:
	@${LN} -s dgd ${WRKDIR}/dgd+net

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@${MV} ${WRKDIR}/dgd/bin/driver ${WRKDIR}/dgd/bin/driver.net
	@${MV} ${WRKDIR}/dgd/bin/precomp ${WRKDIR}/dgd/bin/precomp.net
	@${MV} ${WRKDIR}/dgd/doc/Introduction ${WRKDIR}/dgd/doc/Introduction.NET
	@${MV} ${WRKDIR}/dgd/doc/kfun/send_message ${WRKDIR}/dgd/doc/kfun/send_message.NET
	@${CHMOD} o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-${MV} ${PREFIX}/dgd/bin/driver.net ${PREFIX}/dgd/bin/driver.net.old
	@tar -C ${WRKDIR} -cf - `${GREP} '^dgd/' ${PLIST}` \
		| tar -C ${PREFIX} -xpf -

.include <bsd.port.mk>
