# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	gl2ps
PORTVERSION=	1.3.9
PORTREVISION=	2
CATEGORIES=	print graphics
MASTER_SITES=	http://www.geuz.org/gl2ps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	C library providing vector output for OpenGL application

USE_GL=		yes
USE_XORG=	x11 xmu xi
USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

OPTIONS_DEFINE=	DOCS

pre-build:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libgl2ps.so ${STAGEDIR}${PREFIX}/lib
	${LN} -s {PREFIX}/lib/libgl2ps.so ${STAGEDIR}${PREFIX}/lib/libgl2ps.so.1
	${INSTALL_DATA} ${WRKSRC}/libgl2ps.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gl2ps.h ${STAGEDIR}${PREFIX}/include

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2psTest.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2psTestSimple.c ${STAGEDIR}${EXAMPLESDIR}
	@${SED} -e 's|%%CC%%|${CC}|g; \
		    s|%%RM%%|${RM}|g; \
		    s|%%CFLAGS%%|${CFLAGS}|g; \
		    s|%%LOCALBASE%%|${LOCALBASE}|g' \
		<${FILESDIR}/Makefile.ex >${STAGEDIR}${EXAMPLESDIR}/Makefile

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2ps.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
