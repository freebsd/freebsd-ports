# New ports collection makefile for:	cpuburn
# Date created:				Apr 1, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	cpuburn
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://pages.sbcglobal.net/redelm/
DISTNAME=	cpuburn_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	markp@FreeBSD.org
COMMENT=	CPU/memory stress testing utilities

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386

PORTDOCS=	README Design
CPUS=		BX K6 K7 MMX P5 P6
PLIST_FILES=	${CPUS:C+^+bin/burn+g}

do-build:
.for CPU in ${CPUS}
	${CC} -s -nostdlib -o ${WRKSRC}/burn${CPU} ${WRKSRC}/burn${CPU}.S
.endfor

do-install:
.for CPU in ${CPUS}
	${INSTALL_PROGRAM} ${WRKSRC}/burn${CPU} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Design ${DOCSDIR}
.endif

.include <bsd.port.mk>
