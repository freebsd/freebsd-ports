# New ports collection makefile for:    socketbind
# Date created:         		20 Mar 2003
# Whom:                 		Gaspar Chilingarov <nm@web.am>
#
# $FreeBSD$
#

PORTNAME=	socketbind
PORTVERSION=	1
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	nm@web.am
COMMENT=	Library to bind applications on multihomed machines to specefic IP address

INSTALLS_SHLIB=	YES
NOMAN=		YES
INSTALL_TARGET=
PLIST_SUB=	"DOCSDIR=share/doc/${PORTNAME}"

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} -R ${PATCHDIR}/ ${WRKSRC}

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libsocketbind.so.1 ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libsocketbind.so.1 ${PREFIX}/lib/libsocketbind.so
	${MKDIR} ${DOCSDIR}
	${ECHO} "This library allows to bind arbitrary program, " >> ${DOCSDIR}/README
	${ECHO} "which is dynamically linked to libc.so." >> ${DOCSDIR}/README
	${ECHO} "Load library before your program (set environment " >> ${DOCSDIR}/README
	${ECHO} "variable LD_PRELOAD=${PREFIX}/lib/libsocketbind.so.1) " >> ${DOCSDIR}/README
	${ECHO} "and set address to bind to (set environment variable " >> ${DOCSDIR}/README
	${ECHO} "BINDTO=ip address to bind)" >> ${DOCSDIR}/README

.include <bsd.port.mk>
