# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	cpuburn
DISTVERSION=	1_4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/ \
		http://atarininja.org/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	avg
DISTNAME=	cpuburn_${DISTVERSION}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	avg@FreeBSD.org
COMMENT=	CPU/memory stress testing utilities

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	README Design
CPUS=		BX K6 K7 MMX P5 P6
PLIST_FILES=	${CPUS:S+^+bin/burn+}

NO_STAGE=	yes
do-build:
.for CPU in ${CPUS}
	${CC} -m32 -s -nostdlib -o ${WRKSRC}/burn${CPU} ${WRKSRC}/burn${CPU}.S
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
