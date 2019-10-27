# Created by: trasz
# $FreeBSD$

PORTNAME=	gloox
DISTVERSION=	1.0.22
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber/XMPP client library

LICENSE=	GPLv3 # with OpenSSL exception
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libidn.so:dns/libidn \
		libgnutls.so:security/gnutls

USES=		libtool localbase pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTSCOUT=	skipv:1.0.x

OPTIONS_DEFINE=		MDNSRESPONDER TEST

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_CONFIGURE_ENABLE=	mdns
TEST_CONFIGURE_WITH=	tests

post-patch:
	@${REINPLACE_CMD} -e \
		's| -ansi|| ; \
		 s|\(enable_mdns=\)yes|\1$$enableval|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| -pedantic|| ; \
		 s| -pipe||'

.include <bsd.port.mk>
