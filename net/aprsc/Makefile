# $FreeBSD$

PORTNAME=	aprsc
PORTVERSION=	2.0.19
PORTREVISION=	0
DISTVERSIONSUFFIX=	.g05a4d35
CATEGORIES=	net hamradio
MASTER_SITES=	http://he.fi/aprsc/down/ \
		LOCAL/db

MAINTAINER=	toyokun@gmail.com
COMMENT=	Plain APRS-IS server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
USES=		perl5 gmake shebangfix
SHEBANG_FILES=	aprsc_munin

CONFIGURE_ARGS=	--with-openssl

.include <bsd.port.mk>
