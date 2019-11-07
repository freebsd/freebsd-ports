# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsniff
DISTVERSION=	2.4b1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/${PORTNAME}/beta/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:net/libnids
LIB_DEPENDS=	libnet.so:net/libnet

USES=		gettext gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
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

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085
USES+=		ssl
.endif

.if (${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085) || ${SSL_DEFAULT} == openssl111
# Requires LibreSSL for old SSL interface
BUILD_DEPENDS+=		${NONEXISTENT}:security/libressl:stage
CPPFLAGS+=		-nostdinc -I/usr/include -I${WRKDIR}/libressl/include
LDFLAGS+=		-L${WRKDIR}/libressl/lib
CONFIGURE_ARGS+=	--with-openssl=${WRKDIR}/libressl

# Don't use COPYTREE_SHARE here as it hard links files, and the original files
# are owned by root, which creates problems of its own.
pre-configure:
	@cd `${MAKE} -V STAGEDIR -C ${PORTSDIR}/security/libressl`${PREFIX} \
	    && ${FIND} -E . ! -name *.so\* | ${CPIO} -dump ${WRKDIR}/libressl >/dev/null 2>&1
.else
BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	incomplete definition of type 'struct rsa_st'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,csin,_csin,g' \
		${WRKSRC}/webmitm.c \
		${WRKSRC}/sshmitm.c

.include <bsd.port.post.mk>
