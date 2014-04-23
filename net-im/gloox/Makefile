# Created by: trasz
# $FreeBSD$

PORTNAME=	gloox
PORTVERSION=	1.0.10
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber/XMPP client library

LICENSE=	GPLv3

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libgnutls.so:${PORTSDIR}/security/gnutls

USES=		compiler:c++11-lang libtool:keepla pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lgcrypt||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
