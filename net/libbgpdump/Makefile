# $FreeBSD$

PORTNAME=	libbgpdump
PORTVERSION=	1.6.0
CATEGORIES=	net
MASTER_SITES=	https://www.ris.ripe.net/source/bgpdump/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Analyzing dump files produced by Zebra/Quagga or MRT

LICENSE=	GPLv2

USES=		tar:tgz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bgpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libbgpdump.* ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbgpdump.so
.for i in bgpdump_attr.h bgpdump_formats.h bgpdump_lib.h
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/include
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
