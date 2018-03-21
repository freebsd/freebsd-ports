# $FreeBSD$

PORTNAME=		carbon-relay-ng
DISTVERSIONPREFIX=	v
DISTVERSION=		0.9.4
CATEGORIES=		net-mgmt

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Go implementation of carbonapi

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		go>=1.8:lang/go \
			go-bindata:devel/go-bindata

USES=			gmake

USE_GITHUB=		yes
GH_ACCOUNT=		graphite-ng
GH_SUBDIR=		src/github.com/${GH_ACCOUNT}/${PORTNAME}
USE_RC_SUBR=		${PORTNAME}

USERS=			carbon
GROUPS=			carbon

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} VERSION=${DISTVERSION} \
		${MAKE_CMD} build

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/carbon-relay-ng
	@${MKDIR} ${STAGEDIR}/var/run/carbon-relay-ng
	@${MKDIR} ${STAGEDIR}/var/run/carbon-relay-ng/spool
	${INSTALL_PROGRAM} ${WRKSRC}/carbon-relay-ng ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/carbon-relay-ng.ini ${STAGEDIR}${PREFIX}/etc/carbon-relay-ng/carbon-relay-ng.ini.sample

.include <bsd.port.mk>
