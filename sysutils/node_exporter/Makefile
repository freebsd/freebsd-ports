PORTNAME=	node_exporter
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=v
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Prometheus exporter for machine metrics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=	node_exporter

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

OPTIONS_DEFINE=	DOCS

BUILD_USER?=	${USER}
LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME:H}/common/version

# This Makefile includes the GH_TUPLE section.
# Generated with: env M2T_GITHUB=$M2T_GITHUB make gomod-vendor > out
.include "Makefile.modules"

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
