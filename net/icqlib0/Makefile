# New ports collection makefile for:    icqlib
# Date created:                         16 March 1999
# Whom:                                 Pavel Andreev
#
# $FreeBSD$
#

PORTNAME=	icqlib
PORTVERSION=	0.1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

LIB_VERSION=	1

do-install:
	${INSTALL_DATA} ${WRKSRC}/icqlib/.libs/libicq.so.${LIB_VERSION} \
		${PREFIX}/lib/libicq0.so.${LIB_VERSION}
	${INSTALL_DATA} ${WRKSRC}/icqlib/.libs/libicq.a \
		${PREFIX}/lib/libicq0.a
	${INSTALL_DATA} ${WRKSRC}/icqlib/icq.h ${PREFIX}/include/icq0.h

post-install:
	${LN} -sf libicq0.so.${LIB_VERSION} ${PREFIX}/lib/libicq0.so

.include <bsd.port.mk>
