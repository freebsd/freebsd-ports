# $FreeBSD$

PORTNAME=	rcracki_mt
PORTVERSION=	0.7.0
CATEGORIES=	security
MASTER_SITES=	SF/rcracki/rcracki_mt/rcracki_mt_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src
EXTRACT_SUFX=	.7z

MAINTAINER=	olivier@cochard.me
COMMENT=	Rainbow table based crack tool

LICENSE=	GPLv2

EXTRACT_DEPENDS=7z:${PORTSDIR}/archivers/p7zip

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_GMAKE=	yes
EXTRACT_CMD=	${LOCALBASE}/bin/7z
EXTRACT_BEFORE_ARGS=x -o${WRKDIR}
EXTRACT_AFTER_ARGS=

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ChangeLog.txt README.txt

post-patch:
	@${REINPLACE_CMD} -e 's,CC = g++,CXX ?= g++, ; s,CFLAGS =,CXXFLAGS +=, ; \
		s,-lpthread,${PTHREAD_LIBS}, ; s,CC,CXX, ; s,CFLAGS,CXXFLAGS,' \
		${WRKSRC}/Makefile

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
