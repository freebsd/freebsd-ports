# New ports collection makefile for:	cpuburn
# Date created:				Apr 1, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	cpuburn
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://users.ev1.net/~redelm/
DISTNAME=	cpuburn_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	markp@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386

do-build:
.for CPU in BX K6 K7 MMX P5 P6
	${CC} -s -nostdlib -o ${WRKSRC}/burn${CPU} ${WRKSRC}/burn${CPU}.S
.endfor

do-install:
.for CPU in BX K6 K7 MMX P5 P6
	${INSTALL_PROGRAM} ${WRKSRC}/burn${CPU} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/Design ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
