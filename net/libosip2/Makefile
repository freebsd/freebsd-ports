PORTNAME=	libosip2
PORTVERSION=	5.3.0
CATEGORIES=	net
MASTER_SITES=	GNU/osip

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Low layer of SIP implementation

LICENSE=	LGPL21

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-trace
INSTALL_TARGET=	install-strip
PLIST_SUB=	ABIVER=15

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
