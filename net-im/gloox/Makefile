# Created by: trasz
# $FreeBSD$

PORTNAME=	gloox
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber/XMPP client library

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libgnutls.so:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=	pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|libgnutls-config|pkg-config gnutls|' ${WRKSRC}/configure

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/include/gloox ! -type d | \
		${SED} "s,${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${PREFIX}/include/gloox -type d | ${SORT} -r | \
		${SED} "s,${STAGEDIR}${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
