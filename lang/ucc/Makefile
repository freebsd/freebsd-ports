PORTNAME=	ucc
PORTVERSION=	1.6.2
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.6/
DISTNAME=	ucc162

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C Compiler Which Implements the ANSI C89 Standard

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		dos2unix zip

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:	.SILENT
	${REINPLACE_CMD} 's/make/$$(MAKE)/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/^CC[[:blank:]]*=/d' \
		-e '/^CFLAGS/ { s/=/+=/; s/-g//; }' \
		-e '/:[[:blank:]]/s/\.c/.o/g' \
		-e 's/$$^/$$>/g' \
		${WRKSRC}/driver/Makefile \
		${WRKSRC}/ucl/Makefile
	${REINPLACE_CMD} -e 's#$${PREFIX}#${STAGEDIR}${PREFIX}#g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
