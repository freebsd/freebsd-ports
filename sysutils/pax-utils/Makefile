# New ports collection makefile for:	pax-utils
# Date created:		20 July 2006
# Whom:			Timothy Redaelli
#
# $FreeBSD$
#

PORTNAME=	pax-utils
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://dev.gentoo.org/~vapier/dist/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		true
USE_GMAKE=	true

PLIST_FILES=	bin/dumpelf bin/pspax bin/scanelf bin/scanmacho

PORTDOCS=	BUGS README TODO

MAN1=		dumpelf.1 pspax.1 scanelf.1 scanmacho.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800076
BROKEN=	Does not build
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.for f in ${MAN1:S,.1,,}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/,} ${PREFIX}/man/man1

.include <bsd.port.mk>
