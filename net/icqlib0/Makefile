# New ports collection makefile for:    icqlib
# Date created:                         16 March 1999
# Whom:                                 Pavel Andreev
#
# $FreeBSD$
#

PORTNAME=	icqlib
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

LATEST_LINK=	icqlib0

post-install:
	${INSTALL_DATA} ${WRKSRC}/icqlib/icq.h ${PREFIX}/include/icq0.h

.include <bsd.port.mk>
