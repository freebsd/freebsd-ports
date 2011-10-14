# ex:ts=8
# Ports collection makefile for:	libvncserver
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libvncserver
PORTVERSION=	0.9.8.1
CATEGORIES=	net devel
MASTER_SITES=	SF
DISTNAME=	LibVNCServer-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Provide an easy API to write one's own vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-x

OPTIONS= GNUTLS "Adds GnuTLS support" Off \
	 GCRYPT "Adds Libgcrypt support" Off

.include <bsd.port.options.mk>

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if defined(WITH_GCRYPT)
LIB_DEPENDS+=	gcrypt.18:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-gcrypt
.else
CONFIGURE_ARGS+=	--without-gcrypt
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|x11vnc||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${PREFIX}/include/rfb

.include <bsd.port.mk>
