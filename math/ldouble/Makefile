# New ports collection makefile for:	ldouble
# Date created:		2004-09-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldouble
PORTVERSION=	0.1
CATEGORIES=	math
MASTER_SITES=	http://www.moshier.net/
DISTNAME=	ldouble

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Long double math precision functions

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	lib/libml.a \
		lib/libml.so \
		lib/libml.so.0 \
		include/mathl.h

PORTDOCS=	ldoubdoc.html

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; s|%%CFLAGS%%|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ldoubdoc.html ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/libml.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libml.so.0 ${PREFIX}/lib
	${LN} -sf libml.so.0 ${PREFIX}/lib/libml.so
	${INSTALL_DATA} ${WRKSRC}/protos.h ${PREFIX}/include/mathl.h

.include <bsd.port.mk>
