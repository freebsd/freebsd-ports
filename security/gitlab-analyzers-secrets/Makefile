PORTNAME=	secrets
DISTVERSIONPREFIX=	v
DISTVERSION=	7.20.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://gitlab.com/api/v4/projects/60960406/packages/generic/secret-detection-rules/${SECRET_DETECTION_RULES_VERSION}/:rules \
		https://gitlab.com/gitlab-org/security-products/post-analyzers/scripts/-/raw/v${POST_ANALYZER_SCRIPTS_VERSION}/:script
PKGNAMEPREFIX=	gitlab-analyzers-
DISTFILES=	secret-detection-rules-${SECRET_DETECTION_RULES_VERSION}.zip:rules \
		start.sh:script
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Secret detection scanner for Gitlab
WWW=		https://gitlab.com/gitlab-org/security-products/analyzers/secrets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
RUN_DEPENDS=	gitleaks:devel/gitleaks \
		git>=0:devel/git

USES=		go:modules tar:bzip2

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org/security-products/analyzers

GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/gitlab-org/security-products/analyzers/secrets/v6

GO_TARGET=	${PORTNAME}:analyzer-binary
GO_BUILDFLAGS=	-ldflags="-X '${GO_MODULE}/metadata.AnalyzerVersion=${DISTVERSIONFULL}'"

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

# Versions
# These version can be found in https://gitlab.com/gitlab-org/security-products/analyzers/secrets/-/blob/master/Dockerfile
SECRET_DETECTION_RULES_VERSION=	v0.20.1
POST_ANALYZER_SCRIPTS_VERSION=	0.3.0

# Define where the rules should be extracted
RULES_DIR=	${WRKDIR}/rules
POSTSCRIPT_DIR=	${WRKDIR}/script

post-extract:
	# Create rules directory and extract the zip file there
	${MKDIR} ${RULES_DIR}
	${UNZIP_CMD} -q -d ${RULES_DIR} ${DISTDIR}/${DIST_SUBDIR}/secret-detection-rules-${SECRET_DETECTION_RULES_VERSION}.zip

	# Gitlab pipeline integration script
	${MKDIR} ${POSTSCRIPT_DIR}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/start.sh ${POSTSCRIPT_DIR}/analyzer
	# the binary that is executed is locate in /usr/local/bin, replace this
	${REINPLACE_CMD} -e 's|SCRIPT_BASE_DIR="\$${SCRIPT_BASE_DIR:=/}"|SCRIPT_BASE_DIR="\$${SCRIPT_BASE_DIR:=${PREFIX}/bin}"|' \
		${POSTSCRIPT_DIR}/analyzer

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/rules/dist/all_rules.toml ${STAGEDIR}${DATADIR}/gitleaks.toml
	${INSTALL} -m 0555 ${POSTSCRIPT_DIR}/analyzer ${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/analyzer \
		bin/analyzer-binary \
		${DATADIR}/gitleaks.toml

.include <bsd.port.mk>
