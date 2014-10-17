# Created by: Frederic Dubuy <fdubuy@free.fr>
# $FreeBSD$

PORTNAME=	mifluz
PORTVERSION=	0.25.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to build and query a full text inverted index

LICENSE=	GPLv3

USE_GCC=	any
USES=		bison iconv libtool makeinfo pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-unac
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

INFO=		mifluz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE -pthread|${PTHREAD_CFLAGS}|g' \
		${WRKSRC}/configure


.include <bsd.port.mk>
