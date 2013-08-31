# Created by: David Magda <dmagda+howl@ee.ryerson.ca>
# $FreeBSD$

PORTNAME=	howl
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES?=	net devel
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	freebsd@donovansbrain.co.uk
COMMENT=	Zeroconf/Bonjour(tm) implementation

CONFLICTS=	avahi-[0-9]*

USE_AUTOTOOLS=	libtool
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

USE_RC_SUBR=	mdnsresponder

PLIST_SUB=	VERSION="${PORTVERSION}"

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN8=		mDNSResponder.8

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure

.include <bsd.port.mk>
