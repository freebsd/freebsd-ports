# New ports collection makefile for:	pax-utils
# Date created:		20 July 2006
# Whom:			Timothy Redaelli
#
# $FreeBSD$
#

PORTNAME=	pax-utils
PORTVERSION=	0.2.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://dev.gentoo.org/~vapier/dist/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries

USE_BZIP2=	true
USE_GMAKE=	true

PLIST_FILES=	bin/dumpelf bin/pspax bin/scanelf bin/scanmacho

PORTDOCS=	BUGS README TODO

MAN1=		${PLIST_FILES:S,bin/,,:S,$,.1,}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	${INSTALL_SCRIPT} ${PLIST_FILES:S,bin/,,:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/,} ${PREFIX}/man/man1

.include <bsd.port.mk>
