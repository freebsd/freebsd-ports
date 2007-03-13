# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	2.1.2
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.pwsp.net/downloads/${PORTVERSION}/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

CONFLICTS=	ktorrent-devel-[0-9]*

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|zeroconf||' ${WRKSRC}/plugins/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} \
		-e '/^INCLUDES =/{:loop' -e '/\\$$/{N;bloop' \
		-e '};/$$(all_includes)/{s///;s/$$/ $$(all_includes)/' \
		-e '}' -e '}'

.include <bsd.port.mk>
