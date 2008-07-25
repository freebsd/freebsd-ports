# New ports collection makefile for:	pax-utils
# Date created:		20 July 2006
# Whom:			Timothy Redaelli
#
# $FreeBSD$
#

PORTNAME=	pax-utils
PORTVERSION=	0.1.15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://dev.gentoo.org/~solar/pax/ \
		http://dev.gentoo.org/~vapier/dist/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	drizzt@gufi.org
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries

USE_BZIP2=	true
USE_GMAKE=	true

PLIST_FILES=	bin/dumpelf bin/pspax bin/scanelf

DOCS=		BUGS README TODO

MAN1=		dumpelf.1 pspax.1 scanelf.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dumpelf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pspax ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scanelf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/* ${PREFIX}/man/man1

.include <bsd.port.mk>
