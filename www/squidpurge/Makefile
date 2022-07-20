PORTNAME=	squidpurge
PORTVERSION=	1.17
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/ \
		http://www.squid-cache.org/contrib/
DISTNAME=	purge-20040201-src

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Powerful object purging utility for the Squid web proxy cache

LICENSE=	MIT

USES=		gmake
WRKSRC=		${WRKDIR}/purge

PLIST_FILES=	sbin/purge

post-patch:
	${REINPLACE_CMD} -e 's|= g++|= ${CXX}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/purge ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
