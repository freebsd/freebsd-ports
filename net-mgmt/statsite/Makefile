# $FreeBSD$

PORTNAME=	statsite
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	rbarabas@rbarabas.info
COMMENT=	C implementation of statsd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	armon

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USERS=		statsd
GROUPS=		statsd

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-install:
	${INSTALL_DATA} ${WRKSRC}/rpm/statsite.conf.example \
		${STAGEDIR}${PREFIX}/etc/statsite.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
