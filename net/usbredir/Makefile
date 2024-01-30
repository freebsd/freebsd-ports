PORTNAME=	usbredir
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://spice-space.org/download/usbredir/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Protocol for redirection of USB traffic
WWW=		https://cgit.freedesktop.org/spice/usbredir

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

USES=		gmake libtool pathfix pkgconfig tar:bzip2

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's|SOL_TCP|IPPROTO_TCP|' \
	       ${WRKSRC}/usbredirserver/usbredirserver.c
.include <bsd.port.mk>
