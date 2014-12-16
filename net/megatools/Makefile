# Created by: Max V. Kostikov <max@kostikov.co>
# $FreeBSD$

PORTNAME=	megatools
PORTVERSION=	1.9.93
CATEGORIES=	net
MASTER_SITES=	http://megatools.megous.com/builds/

MAINTAINER=	max@kostikov.co
COMMENT=	Tools for MEGA.CO.NZ cloud drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	glib-networking>=2.29.18:${PORTSDIR}/net/glib-networking

USES=		gmake pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_OPENSSL=	yes

LIBS+=          -lssl -lcrypto

INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection=no

OPTIONS_DEFINE=	FUSE
OPTIONS_DEFAULT=	FUSE
OPTIONS_SUB=	yes

FUSE_USES=	fuse
FUSE_CONFIGURE_WITH=	fuse

post-patch:
	@${REINPLACE_CMD} -e '/MEGA_REQUIRES=/ s|openssl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
