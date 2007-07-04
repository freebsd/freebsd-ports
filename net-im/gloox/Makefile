# New ports collection makefile for:	gloox
# Date created:			24 April 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	gloox
PORTVERSION=	0.9.2
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Jabber/XMPP client library

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn \
		gnutls.13:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

post-install:
	@${FIND} ${PREFIX}/include/gloox ! -type d | \
		${SED} "s,${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/gloox -type d | ${SORT} -r | \
		${SED} "s,${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
