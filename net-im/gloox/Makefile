# Created by: trasz
# $FreeBSD$

PORTNAME=	gloox
PORTVERSION=	1.0.13
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber/XMPP client library

LICENSE=	GPLv3

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libgnutls.so:${PORTSDIR}/security/gnutls

USES=		libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	skipv:1.0.x

post-patch:
	@${REINPLACE_CMD} -e \
		 's| -ansi||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| -pedantic|| ; \
		 s| -pipe||'

.include <bsd.port.mk>
