# $FreeBSD$

PORTNAME=	h323plus
DISTVERSIONPREFIX=	v
DISTVERSION=	1_26_8
CATEGORIES=	net multimedia
MASTER_SITES=	http://www.h323plus.org/source/download/

MAINTAINER=	koue@chaosophia.net
COMMENT=	H323 Video Conferencing library

LICENSE=	MPL10 MPL11
LICENSE_COMB=	multi

LIB_DEPENDS=	libpt.so:devel/ptlib

USES=		gmake ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
# ptlib-config --libs returns bogus dependencies on expat and SDL-1.2
LDFLAGS+=	-Wl,--as-needed
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_JOBS_UNSAFE=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libh323.so

.include <bsd.port.mk>
