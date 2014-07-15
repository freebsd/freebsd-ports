# $FreeBSD$

PORTNAME=	aprsc
PORTVERSION=	2.0.14
PORTREVISION=	2
DISTVERSIONSUFFIX=	.g28c5a6a
CATEGORIES=	net hamradio
MASTER_SITES=	http://he.fi/aprsc/down/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	toyokun@gmail.com
COMMENT=	Plain APRS-IS server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	event2/libevent-2.0.so:${PORTSDIR}/devel/libevent2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/event2
MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
USES=		perl5 gmake shebangfix
SHEBANG_FILES=	aprsc_munin

CONFIGURE_ARGS=	--with-openssl

.include <bsd.port.mk>
