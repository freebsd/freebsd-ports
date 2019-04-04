# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsniff
DISTVERSION=	2.4b1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/${PORTNAME}/beta/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	incomplete definition of type 'struct rsa_st'

BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:net/libnids
LIB_DEPENDS=	libnet.so:net/libnet

USES=		gettext pkgconfig ssl
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet=${LOCALBASE}
DESTDIRNAME=	install_prefix
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/..$//}

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_USE=	xorg=x11,xmu
X11_CONFIGURE_WITH=x

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct rsa_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct rsa_st'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,csin,_csin,g' \
		${WRKSRC}/webmitm.c \
		${WRKSRC}/sshmitm.c

.include <bsd.port.post.mk>
