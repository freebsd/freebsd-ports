PORTNAME=	alloy
DISTVERSION=	1.6.1
DISTVERSIONPREFIX=v
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	zach.leslie@grafana.com
COMMENT=	OpenTelemetry Collector distribution with programmable pipelines
WWW=		https://github.com/grafana/alloy

LICENSE=	MIT

BUILD_DEPENDS=	git:devel/git

USES=		go:1.23,modules

USE_GITHUB=	yes
GH_ACCOUNT=	grafana
GH_PROJECT=	alloy

USE_RC_SUBR=	alloy

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_BUILDFLAGS=	-ldflags='-X github.com/grafana/alloy/internal/build.Version=v${PORTVERSION}'

post-fetch:
	@${ECHO_MSG} "===> Fetching ${GO_MODNAME}/syntax dependency";
	(cd ${DISTDIR}/${DIST_SUBDIR}; [ -e syntax/go.mod ] || (\
		${MKDIR} syntax/; \
		${TAR} -xzf ${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-${PORTVERSION}/syntax/go.mod; \
		${CP} ${PORTNAME}-${PORTVERSION}/syntax/go.mod syntax/go.mod))

post-extract:
	${CP} -r ${WRKDIR}/${PORTNAME}-${PORTVERSION}/syntax ${GO_WRKSRC}/syntax;

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/alloy ${STAGEDIR}${PREFIX}/bin/alloy
	${INSTALL_DATA} ${WRKSRC}/example-config.alloy ${STAGEDIR}${PREFIX}/etc/alloy.flow.sample
	${MKDIR} ${STAGEDIR}/var/alloy

.include <bsd.port.mk>
