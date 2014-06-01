# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	fragroute
PORTVERSION=	1.2
PORTREVISION=	11
CATEGORIES=	security net
MASTER_SITES=	http://monkey.org/~dugsong/fragroute/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for intercepting, modifying, and rewriting egress traffic

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet \
		libevent-1.4.so:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libdnet=${LOCALBASE} \
			--with-libevent=${LOCALBASE} --with-pcap

SCRIPTS=	README.snort base-1 frag-1 frag-2 frag-3 frag-4 frag-5 \
	frag-6 frag-7-unix frag-7-win32 ins-2 ins-3 tcbc-2 tcp-3 tcp-5 \
	tcp-7 tcp-9

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for FILE in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/scripts/${FILE} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
