# New ports collection makefile for:	tn3270
# Date created:		30 August 1999
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	tn3270
PORTVERSION=	4.4
CATEGORIES=	net
MASTER_SITES=	http://people.freebsd.org/~markm/ \
		ftp://ftp.za.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/distfiles/
DISTNAME=	tn3270

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen remote login to IBM VM/CMS

MAN1=		tn3270.1 mset.1
MAN5=		map3270.5
MANCOMPRESSED=	maybe

NEW_TELNETDIR=	/usr/src/contrib/telnet

.if exists(${NEW_TELNETDIR})
LIBTELNETDIR?=	/usr/src/contrib/telnet/libtelnet
.else
LIBTELNETDIR?=	/usr/src/lib/libtelnet
.endif

post-extract:
	@if [ ! -d ${LIBTELNETDIR} ]; then \
		${ECHO} "You need libtelnet sources in"; \
		${ECHO} "${LIBTELNETDIR}"; \
		${ECHO} "to build this port."; \
	exit 1; \
	fi
	${CP} -rp ${LIBTELNETDIR} ${WRKSRC}
.if exists(${NEW_TELNETDIR})
	${CP} ${LIBTELNETDIR}/../arpa/telnet.h ${WRKSRC}/libtelnet
	${SED} -E '/^(TELNETDIR|\.PATH|CFLAGS|INCS)/d' \
		${LIBTELNETDIR}/../../../lib/libtelnet/Makefile > \
		${WRKSRC}/libtelnet/Makefile
.endif

do-configure:
	${ECHO_CMD} "BINDIR=	${PREFIX}/bin" > ${WRKDIR}/Makefile.inc
	${ECHO_CMD} "MANDIR=	${PREFIX}/man/man" >> ${WRKDIR}/Makefile.inc
do-build:
	cd ${WRKSRC}; \
	${MAKE} depend; \
	${MAKE} all

.include <bsd.port.mk>
