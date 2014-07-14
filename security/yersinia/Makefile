# Created by: se
# $FreeBSD$

PORTNAME=	yersinia
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.yersinia.net/download/

MAINTAINER=	ayu@commun.jp
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

.if !defined(WITHOUT_GTK)
.if exists(${LOCALBASE}/include/gtk-2.0/gtk/gtk.h)
WITH_GTK=	true
.endif
.endif
.if defined(WITH_GTK)
USES=		pkgconfig
USE_GNOME+=	gtk20
PKGNAMESUFFIX=	-gtk
CONFLICTS=	yersinia-[0-9]*
.else
CONFIGURE_ARGS+=	--disable-gtk
CONFLICTS=	yersinia-gtk-[0-9]*
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBNET_CONFIG="${LIBNET_CONFIG}"

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

#NOT_FOR_ARCHS=	ia64 sparc64
PLIST_FILES=	sbin/yersinia \
		man/man8/yersinia.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/yersinia.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
