PORTNAME=	bgpq3
PORTVERSION=	0.1.36
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	snar@snar.spb.ru
COMMENT=	Lightweight prefix-list generator for various routers
WWW=		https://github.com/snar/bgpq3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
GH_ACCOUNT=	snar

PLIST_FILES=	bin/bgpq3 \
		share/man/man8/bgpq3.8.gz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${STAGEDIR}${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|man/man8|share/man/man8|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
