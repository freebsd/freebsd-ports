PORTNAME=	bgpuma
PORTVERSION=	20151209
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Searching BGP update files

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libbgpdump.so:net/libbgpdump \
		libsilk.so:security/silktools

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	cmu-sei
GH_TAGNAME=	a29b2a7
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/bgpuma man/man1/bgpuma.1.gz

.include <bsd.port.mk>
