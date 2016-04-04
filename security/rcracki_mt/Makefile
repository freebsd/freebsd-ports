# $FreeBSD$

PORTNAME=	rcracki_mt
PORTVERSION=	0.7.0
CATEGORIES=	security
MASTER_SITES=	SF/rcracki/rcracki_mt/rcracki_mt_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Rainbow table based crack tool

LICENSE=	GPLv2

NOT_FOR_ARCHS=	arm sparc64
NOT_FOR_ARCHS_REASON=	cannot detect endianness

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USES=		7z gmake

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ChangeLog.txt README.txt

post-patch:
	@${REINPLACE_CMD} -e 's,CC = g++,CXX ?= g++, ; \
		s,CFLAGS =,CXXFLAGS +=, ; s,CC,CXX, ; s,CFLAGS,CXXFLAGS,' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
