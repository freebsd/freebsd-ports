PORTNAME=	bgpq4
PORTVERSION=	1.5
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight prefix-list generator for various routers v4

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		autoreconf compiler:c11 libtool
USE_GITHUB=	yes
GH_ACCOUNT=	bgp

GNU_CONFIGURE=	yes

MAKE_ARGS+=	CC="${CC}"

PLIST_FILES=	bin/bgpq4 \
		man/man8/bgpq4.8.gz

.include <bsd.port.mk>
