PORTNAME=	node_exporter
DISTVERSIONPREFIX=v
DISTVERSION=	1.8.2
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Prometheus exporter for machine metrics
WWW=		https://github.com/prometheus/node_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules shebangfix
USE_RC_SUBR=	node_exporter

GO_MODULE=	github.com/prometheus/${PORTNAME}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

OPTIONS_DEFINE=	DOCS

BUILD_USER?=	${USER}
LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}
LD_FLAG_X_PREFIX=	-X github.com/prometheus/common/version

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
