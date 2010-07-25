# Ports collection makefile for:  vomit
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vomit
PORTVERSION=	0.2c
PORTREVISION=	7
CATEGORIES=	net security
MASTER_SITES=	http://vomit.xtdnet.nl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Voice over misconfigured internet telephones

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent \
		dnet.1:${PORTSDIR}/net/libdnet

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		vomit.1
PLIST_FILES=	bin/vomit

BROKEN=		does not build with new libevent

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -Wall -g|@CFLAGS@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
