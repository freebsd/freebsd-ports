# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	ucc
PORTVERSION=	1.6.0
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	ucc160

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C Compiler Which Implements the ANSI C89 Standard

USES=		dos2unix zip
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_LDCONFIG=	yes

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

.include <bsd.port.mk>
