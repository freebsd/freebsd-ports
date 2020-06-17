# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	node_exporter
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Prometheus exporter for machine metrics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	promtool:net-mgmt/prometheus2 \
		bash:shells/bash \
		gsed:textproc/gsed

USES=		gmake go:modules shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=	node_exporter

# The ttar script is used to run the tests.
SHEBANG_FILES=	ttar

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

# A "checkrules" target is being added in >0.17.0.
TEST_TARGET=	test

TEST_ENV=	PROMTOOL=${LOCALBASE}/bin/promtool

BUILD_USER?=	${USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME:H}/common/version
LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

# TestFileDescriptorLeak is being skipped at the moment because procfs(5) is
# not properly detected.
pre-test:
	# Prevent Go from attempting to use Git to redownload its dependencies.
	# They are already present in ${WRKSRC}/vendor.
	${RM} ${WRKSRC}/go.mod

	${REINPLACE_CMD} -e 's|sed|${LOCALBASE}/bin/gsed|g' ${WRKSRC}/ttar

	${RM} -r ${WRKDIR}/src
	${LN} -sf ${WRKSRC}/vendor ${WRKDIR}/src
	${MKDIR} ${WRKSRC}/vendor/${GO_PKGNAME}
	${LN} -sf ${WRKSRC}/collector ${WRKSRC}/vendor/${GO_PKGNAME}/collector

	# GOPATH has to have exactly one element in order to have the test
	# suite detect the node_exporter binary. "-v" is added here for us to
	# see skipped tests.
	${REINPLACE_CMD} -E 's|(\$$\(GO\) test)|env GOPATH="${WRKDIR}" \1 -v|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
