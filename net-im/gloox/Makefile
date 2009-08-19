# New ports collection makefile for:	gloox
# Date created:			24 April 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	gloox
PORTVERSION=	0.9.9.7
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Jabber/XMPP client library

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn \
		gnutls.40:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|libgnutls-config|pkg-config gnutls|' ${WRKSRC}/configure
post-install:
	@${FIND} ${PREFIX}/include/gloox ! -type d | \
		${SED} "s,${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/gloox -type d | ${SORT} -r | \
		${SED} "s,${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
