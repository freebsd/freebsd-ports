PORTNAME=	socketbind
PORTVERSION=	1
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	nm@web.am
COMMENT=	Library to bind applications on multihomed machines to specific IP address

USE_LDCONFIG=	YES
INSTALL_TARGET=

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} -R ${PATCHDIR}/ ${WRKSRC}

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libsocketbind.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libsocketbind.so.1 ${STAGEDIR}${PREFIX}/lib/libsocketbind.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${ECHO} "This library allows to bind arbitrary program, " >> ${STAGEDIR}${DOCSDIR}/README
	${ECHO} "which is dynamically linked to libc.so." >> ${STAGEDIR}${DOCSDIR}/README
	${ECHO} "Load library before your program (set environment " >> ${STAGEDIR}${DOCSDIR}/README
	${ECHO} "variable LD_PRELOAD=${PREFIX}/lib/libsocketbind.so.1) " >> ${STAGEDIR}${DOCSDIR}/README
	${ECHO} "and set address to bind to (set environment variable " >> ${STAGEDIR}${DOCSDIR}/README
	${ECHO} "BINDTO=ip address to bind)" >> ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
