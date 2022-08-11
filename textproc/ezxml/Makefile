PORTNAME=	ezxml
PORTVERSION=	0.8.6
CATEGORIES=	textproc devel
MASTER_SITES=	SF/${PORTNAME}/ezXML/ezXML%20${PORTVERSION} \
		http://www.yazzy.org/ports/ezxml/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use C library for parsing XML documents

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

WRKSRC=		${WRKDIR}/${PORTNAME}

LIBFILES=	libezxml.a
HEADERFILES=	ezxml.h

OPTIONS_DEFINE=	EXAMPLES

PLIST_FILES=	include/${HEADERFILES} \
		lib/${LIBFILES}

PORTEXAMPLES=	*

do-install:
	${INSTALL_DATA} ${WRKSRC}/${LIBFILES} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${HEADERFILES} ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ezxml.txt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
