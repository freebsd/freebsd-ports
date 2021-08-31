PORTNAME=	h323plus
DISTVERSIONPREFIX=      v
DISTVERSION=    1_27_2
CATEGORIES=	net multimedia

MAINTAINER=	pi@FreeBSD.org
COMMENT=	H323 Video Conferencing library

LICENSE=	MPL10 MPL11
LICENSE_COMB=	multi

LIB_DEPENDS=	libpt.so:devel/ptlib

USES=		gmake ssl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	willamowius

# ptlib-config --libs returns bogus dependencies on expat and SDL-1.2
CFLAGS+=	-DH323_H46017 -DH323_TLS
LDFLAGS+=	-Wl,--as-needed

MAKE_JOBS_UNSAFE=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libh323.so

.include <bsd.port.mk>
