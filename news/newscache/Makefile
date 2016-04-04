# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	newscache
PORTVERSION=	1.2.r.6
PORTREVISION=	4
CATEGORIES=	news
MASTER_SITES=	http://src.linuxhacker.at/NewsCache/
DISTNAME=	NewsCache-${PORTVERSION:S/.r./rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NewsCache is a free cache server for USENET News

LIB_DEPENDS=	libsocket++.so:net/libsocket++

USES=		autoreconf
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc
USE_RC_SUBR=	${PORTNAME}

INFO=		NewsCache

post-patch:
	${REINPLACE_CMD} -e "s,-pedantic,," \
		-e "s,^main,int main," \
		${WRKSRC}/configure.in

.include <bsd.port.mk>
