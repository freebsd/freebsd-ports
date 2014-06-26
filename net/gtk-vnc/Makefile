# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-vnc
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USE_XZ=		yes
USE_GNOME=	gnomehier gtk30 introspection:build
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 --enable-introspection \
		--disable-plugin --without-python
MAKE_JOBS_UNSAFE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.0

post-patch:
	@${REINPLACE_CMD} '/LDADD/s/GTK_CFLAGS/GTK_LIBS/' \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
