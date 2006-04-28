# New ports collection makefile for:	gloox
# Date created:			24 April 2006
# Whom:				trasz
#
# $FreeBSD$
#

PORTNAME=	gloox
PORTVERSION=	0.8
CATEGORIES=	net-im
MASTER_SITES=	http://camaya.net/download/

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	Jabber/XMPP client library

LIB_DEPENDS=	iksemel.3:${PORTSDIR}/textproc/iksemel \
		idn.16:${PORTSDIR}/dns/libidn \
		gnutls.15:${PORTSDIR}/security/gnutls

USE_BZIP2=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-install:
	@${FIND} ${PREFIX}/include/gloox ! -type d | \
		${SED} "s,${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/gloox -type d | ${SORT} -r | \
		${SED} "s,${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
