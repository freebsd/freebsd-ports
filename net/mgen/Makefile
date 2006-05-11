# New ports collection makefile for:	rude
# Date created:		04/11/2004
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	mgen
PORTVERSION=	4.2b5
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/mgen/
DISTNAME=	src-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	An IP network performance tests and measurements

# Dumps core on 64-bit architectures. This was reported to the upstream
# author, who promised to fix it in one of the next releases.
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

PLIST_FILES=	bin/mgen
PORTDOCS=	README.TXT VERSION.TXT mgen.html example.mgn

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/unix/Makefile.common \
		${WRKSRC}/protolib/unix/Makefile.common

	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g' ${WRKSRC}/unix/Makefile.freebsd \
	                ${WRKSRC}/protolib/unix/Makefile.freebsd

do-build:
	cd ${WRKSRC}/unix && ${GMAKE} -f Makefile.freebsd ${PORTNAME}

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/unix/mgen ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
