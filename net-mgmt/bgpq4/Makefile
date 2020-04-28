# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bgpq4
PORTVERSION=	0.0.6
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight prefix-list generator for various routers v4

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		autoreconf compiler:c11
USE_GITHUB=	yes

MAKE_ARGS+=	CC="${CC}"

GH_ACCOUNT=	bgp

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bgpq4 \
		man/man8/bgpq4.8.gz

.include <bsd.port.mk>
