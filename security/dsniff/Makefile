PORTNAME=	dsniff
DISTVERSION=	2.4b1
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/${PORTNAME}/beta/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing
WWW=		https://www.monkey.org/~dugsong/dsniff/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_14=	fails to compile : conflicting types for 'pcap_init'
BROKEN_FreeBSD_15=	fails to compile : conflicting types for 'pcap_init'

BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:net/libnids
LIB_DEPENDS=	libnet.so:net/libnet

USES=		gettext gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-libnet=${LOCALBASE}
DESTDIRNAME=	install_prefix
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/..$//}

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_USES=	xorg
X11_USE=	xorg=x11,xmu
X11_CONFIGURE_WITH=x

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD || ${SSL_DEFAULT} == openssl
# Requires OpenSSL 1.0.x for old SSL interface
BUILD_DEPENDS+=		${NONEXISTENT}:security/openssl-unsafe:stage
CPPFLAGS+=		-nostdinc -I/usr/include -I${WRKDIR}/openssl-unsafe/include
LDFLAGS+=		-L${WRKDIR}/openssl-unsafe/lib
CONFIGURE_ARGS+=	--with-openssl=${WRKDIR}/openssl-unsafe

# Don't use COPYTREE_SHARE here as it hard links files, and the original files
# are owned by root, which creates problems of its own.
pre-configure:
	@cd `${MAKE} -V STAGEDIR -C ${PORTSDIR}/security/openssl-unsafe`${PREFIX}/openssl-unsafe \
	    && ${FIND} . ! -name *.so\* | ${CPIO} -dump ${WRKDIR}/openssl-unsafe >/dev/null 2>&1
.else
BROKEN_SSL=	openssl
BROKEN_SSL_REASON_openssl=	incomplete definition of type 'struct rsa_st'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,csin,_csin,g' \
		${WRKSRC}/webmitm.c \
		${WRKSRC}/sshmitm.c

.include <bsd.port.post.mk>
