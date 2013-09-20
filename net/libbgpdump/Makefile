# Created by: ijliao
# $FreeBSD$

PORTNAME=	libbgpdump
PORTVERSION=	1.4.99.13
CATEGORIES=	net
MASTER_SITES=	http://www.ris.ripe.net/source/bgpdump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Analyzing dump files produced by Zebra/Quagga or MRT

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	README
PORTEXAMPLES=	example.c

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bgpdump ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/libbgpdump.* ${PREFIX}/lib
.for i in bgpdump_attr.h bgpdump_formats.h bgpdump_lib.h
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/include
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
