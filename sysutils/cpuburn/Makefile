# New ports collection makefile for:	cpuburn
# Date created:				Apr 1, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	cpuburn
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://users.ev1.net/~redelm/
DISTNAME=	cpuburn_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	mark@kyne.com.au

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386

do-build:
	@(cd ${BUILD_WRKSRC}; \
	for CPU in BX K6 MMX P5 P6; do \
		${ECHO} Building burn$$CPU..; \
		${CC} -s -nostdlib -o burn$$CPU burn$$CPU.s; \
	done)

do-install:
	@(for CPU in BX K6 MMX P5 P6; do \
		${ECHO} Installing burn$$CPU..; \
		${INSTALL_PROGRAM} ${WRKSRC}/burn$$CPU ${PREFIX}/bin; \
	done)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/Design ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
