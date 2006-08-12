# New ports collection makefile for:    yersinia
# Date created:         Sun Jul 24 10:43:13 CEST 2005
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	yersinia
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.yersinia.net/download/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet

.if !defined(WITHOUT_GTK)
.if exists(${X11BASE}/include/gtk-2.0/gtk/gtk.h)
WITH_GTK=	true
.endif
.endif
.if defined(WITH_GTK)
USE_GNOME+=	pkgconfig gtk20
PKGNAMESUFFIX=	-gtk
CONFLICTS=	yersinia-[0-9]*
.else
CONFIGURE_ARGS+= --disable-gtk
CONFLICTS=	yersinia-gtk-[0-9]*
.endif
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

#NOT_FOR_ARCHS=	ia64 sparc64
MAN8=		yersinia.8
PLIST_FILES=	sbin/yersinia

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${TARGETDIR}/sbin/
		${INSTALL_MAN} ${WRKSRC}/yersinia.8 ${TARGETDIR}/man/man8/

.include <bsd.port.post.mk>
