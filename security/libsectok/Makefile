# New ports collection makefile for:	libsectok
# Date created:		29 September 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsectok
PORTVERSION=	20030619
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/
DISTNAME=	libsectok-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	ISO 7816 Smartcard API Library

INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_OPENSSL=	YES

MAN3=		sectok.3

do-install:
	${INSTALL_DATA} ${WRKSRC}/sectok.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libsectok.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libsectok.so.3 ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libsectok.so.3 ${PREFIX}/lib/libsectok.so
	${INSTALL_MAN} ${WRKSRC}/sectok.3 ${PREFIX}/man/man3

PLIST_FILES=	include/sectok.h lib/libsectok.a \
		lib/libsectok.so lib/libsectok.so.3

.include <bsd.port.mk>
