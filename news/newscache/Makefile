# New ports collection Makefile for:   newscache
# Date created:                23 February 2002
# Whom:                        Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newscache
PORTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.hstraub.at/linux/downloads/src/ \
		http://www.infosys.tuwien.ac.at/NewsCache/download/
DISTNAME=	NewsCache-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	NewsCache is a free cache server for USENET News

LIB_DEPENDS=	socket[+][+].1:${PORTSDIR}/net/libsocket++

USE_AUTOMAKE_VER=	15
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" 
MAKE_ENV=	LIBS="-lsocket++"

MAN5=	newscache.conf.5
MAN8=	newscache.8 newscacheclean.8 updatenews.8
INFO=	NewsCache

post-patch:
	cd ${WRKSRC}; ./autogen

.include <bsd.port.mk>
