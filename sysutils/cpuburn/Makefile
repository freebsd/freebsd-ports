# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	cpuburn
DISTVERSION=	1_4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/ \
		http://atarininja.org/distfiles/ \
		LOCAL/avg
DISTNAME=	cpuburn_${DISTVERSION}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	avg@FreeBSD.org
COMMENT=	CPU/memory stress testing utilities

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	README Design
CPUS=		BX K6 K7 MMX P5 P6
PLIST_FILES=	${CPUS:S+^+bin/burn+}
USE_GCC=	yes

OPTIONS_DEFINE=	DOCS

do-build:
.for CPU in ${CPUS}
	${CC} -m32 -s -nostdlib -o ${WRKSRC}/burn${CPU} ${WRKSRC}/burn${CPU}.S
.endfor

do-install:
.for CPU in ${CPUS}
	${INSTALL_PROGRAM} ${WRKSRC}/burn${CPU} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/Design ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
