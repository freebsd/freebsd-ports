PORTNAME=	aprsc
PORTVERSION=	2.1.10
PORTREVISION=	1
DISTVERSIONSUFFIX=	.gd72a17c
CATEGORIES=	net hamradio
MASTER_SITES=	http://he.fi/aprsc/down/ \
		LOCAL/db

MAINTAINER=	toyokun@gmail.com
COMMENT=	Plain APRS-IS server
WWW=		http://he.fi/aprsc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		localbase:ldflags ssl perl5 gmake shebangfix
MAKEFILE=	GNUmakefile
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
SHEBANG_FILES=	aprsc_munin

CONFIGURE_ARGS=	--with-openssl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/aprsc

.include <bsd.port.mk>
