PORTNAME=	fragroute
PORTVERSION=	1.2
PORTREVISION=	17
CATEGORIES=	security net
MASTER_SITES=	http://monkey.org/~dugsong/fragroute/ \
		PACKETSTORM/UNIX/security

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Tool for intercepting, modifying, and rewriting egress traffic
WWW=		https://www.monkey.org/~dugsong/fragroute/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libevent.so:devel/libevent

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE} --with-pcap

SCRIPTS=	README.snort base-1 frag-1 frag-2 frag-3 frag-4 frag-5 \
		frag-6 frag-7-unix frag-7-win32 ins-2 ins-3 tcbc-2 tcp-3 \
		tcp-5 tcp-7 tcp-9

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for FILE in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/scripts/${FILE} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
