# $FreeBSD$

PORTNAME=	aprsc
PORTVERSION=	2.1.4
DISTVERSIONSUFFIX=	.g408ed49
PORTREVISION=	2
CATEGORIES=	net hamradio
MASTER_SITES=	http://he.fi/aprsc/down/ \
		LOCAL/db

MAINTAINER=	toyokun@gmail.com
COMMENT=	Plain APRS-IS server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
USES=		localbase:ldflags ssl perl5 gmake shebangfix
SHEBANG_FILES=	aprsc_munin

CONFIGURE_ARGS=	--with-openssl

.include <bsd.port.mk>
