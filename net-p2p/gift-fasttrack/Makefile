# New ports collection makefile for:	giFT-FastTrack
# Date created:		2003-09-04
# Whom:			Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	giFT-FastTrack
PORTVERSION=	0.8.9
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/gift-fasttrack/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	A FastTrack plugin for giFT

LIB_DEPENDS=	gift.0:${PORTSDIR}/net/gift

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS COPYING ChangeLog \
		INSTALL NEWS README TODO

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
