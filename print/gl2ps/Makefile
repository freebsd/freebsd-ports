# New ports collection makefile for: gl2ps
# Date created:		31 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	gl2ps
PORTVERSION=	1.1.2
CATEGORIES=	print graphics
MASTER_SITES=	http://www.geuz.org/gl2ps/src/

MAINTAINER=	tiamat@comset.net
COMMENT=	A C library providing vector output for OpenGL application

USE_GL=		yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

pre-build:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libgl2ps.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libgl2ps.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gl2ps.h ${PREFIX}/include

	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2psTest.c ${EXAMPLESDIR}
	@${PERL} -pi -e 's|%%CC%%|${CC}|g; \
			 s|%%RM%%|${RM}|g; \
			 s|%%CFLAGS%%|${CFLAGS}|g; \
			 s|%%X11BASE%%|${X11BASE}|g' \
		<${FILESDIR}/Makefile.ex >${EXAMPLESDIR}/Makefile

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gl2ps.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
