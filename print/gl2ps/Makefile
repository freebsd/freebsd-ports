# New ports collection makefile for: gl2ps
# Date created:		31 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	gl2ps
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	print graphics
MASTER_SITES=	http://www.geuz.org/gl2ps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A C library providing vector output for OpenGL application

USE_GL=		yes
USE_XORG=	x11 xmu xi
USE_LDCONFIG=	yes

pre-build:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libgl2ps.so ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libgl2ps.so ${PREFIX}/lib/libgl2ps.so.1
	${INSTALL_DATA} ${WRKSRC}/libgl2ps.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gl2ps.h ${PREFIX}/include

	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2psTest.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2psTestSimple.c ${EXAMPLESDIR}
	@${SED} -e 's|%%CC%%|${CC}|g; \
		    s|%%RM%%|${RM}|g; \
		    s|%%CFLAGS%%|${CFLAGS}|g; \
		    s|%%LOCALBASE%%|${LOCALBASE}|g' \
		<${FILESDIR}/Makefile.ex >${EXAMPLESDIR}/Makefile

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2ps.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
