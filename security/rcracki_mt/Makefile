# $FreeBSD$

PORTNAME=	rcracki_mt
PORTVERSION=	0.7.0
CATEGORIES=	security
MASTER_SITES=	SF/rcracki/rcracki_mt/rcracki_mt_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Rainbow table based crack tool

LICENSE=	GPLv2

NOT_FOR_ARCHS=	aarch64 armv6 armv7 mips mips64 sparc64
NOT_FOR_ARCHS_REASON=	cannot detect endianness

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USES=		7z gmake ssl

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ChangeLog.txt README.txt

post-patch:
	@${REINPLACE_CMD} \
		-e 's,CC = g++,CXX ?= g++,' \
		-e 's,CFLAGS =,CXXFLAGS +=,' \
		-e 's,CC,CXX,' \
		-e 's,CFLAGS,CXXFLAGS,' \
		-e "s|\(INCLUDES = .*\)|\1 -I${OPENSSLINC}|g" \
		-e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
