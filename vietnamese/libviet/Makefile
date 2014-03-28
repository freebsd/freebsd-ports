# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	libviet
PORTVERSION=	20010210
PORTREVISION=	1
CATEGORIES=	vietnamese devel
MASTER_SITES=	LOCAL/obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	VIQR<->VISCII conversion and VISCII ctype-like routines

USES=		tar:bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/lib

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/libvntype.a ${WRKSRC}/libviqr.a \
		${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/viet
	(cd ${WRKSRC}/../include && ${INSTALL_DATA} charset.h charseta.h \
		charsetv.h ctype.h portable.h vncompos.h vnkeys.h vntype.h \
		${STAGEDIR}${PREFIX}/include/viet)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README.lib ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
