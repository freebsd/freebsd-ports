# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.2p2
CATEGORIES=	net lang
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|} \
		ftp://ftp.dworkin.nl/pub/dgd/ \
		ftp://ftp.imaginary.com/pub/LPC/servers/DGD/

PATCH_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd/patches|} \
		ftp://ftp.dworkin.nl/pub/dgd/patches \
		ftp://ftp.imaginary.com/pub/LPC/servers/DGD/patches/

MAINTAINER=	glewis@FreeBSD.org

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
