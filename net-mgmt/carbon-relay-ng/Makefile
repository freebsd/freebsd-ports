PORTNAME=		carbon-relay-ng
DISTVERSION=		0.10.0
PORTREVISION=	14
CATEGORIES=		net-mgmt

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Go implementation of carbonapi
WWW=		https://github.com/graphite-ng/carbon-relay-ng

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		go-bindata:devel/go-bindata

USES=			gmake go

USE_GITHUB=		yes
GH_ACCOUNT=		graphite-ng
GH_SUBDIR=		src/github.com/${GH_ACCOUNT}/${PORTNAME}
USE_RC_SUBR=		${PORTNAME}

GO_TARGET=		./cmd/${PORTNAME}

USERS=			carbon
GROUPS=			carbon

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/carbon-relay-ng
	@${MKDIR} ${STAGEDIR}/var/run/carbon-relay-ng
	@${MKDIR} ${STAGEDIR}/var/run/carbon-relay-ng/spool
	${INSTALL_DATA} ${WRKSRC}/examples/carbon-relay-ng.ini ${STAGEDIR}${PREFIX}/etc/carbon-relay-ng/carbon-relay-ng.ini.sample

.include <bsd.port.mk>
