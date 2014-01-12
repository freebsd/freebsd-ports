# Created by: CHOI Junho <cjh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qdecoder
PORTVERSION=	12.0.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	qDecoder-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C/C++ language library including CGI supports

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	exec_prefix="${PREFIX}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	${REINPLACE_CMD} 's/.{[A-Z]*DIR/$${DESTDIR}&/' ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} '/<limits/{p;s//<errno/;}' ${WRKSRC}/src/qcgireq.c

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} "Makefile *.c *.html" \
		${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libqdecoder.so

.include <bsd.port.mk>
