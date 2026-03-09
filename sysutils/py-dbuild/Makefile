PORTNAME=	dbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Build, test, and push FreeBSD OCI container images
WWW=		https://daemonless.io/guides/dbuild

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		buildah:sysutils/buildah \
		podman:sysutils/podman

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	daemonless
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=		COMPOSE_TESTING DOCS MULTI_ARCH_MANIFESTS SBOM \
			SCREENSHOT_TESTING
OPTIONS_DEFAULT=	MULTI_ARCH_MANIFESTS SBOM

COMPOSE_TESTING_DESC=		Compose testing
MULTI_ARCH_MANIFESTS_DESC=	Multi-arch manifests
SBOM_DESC=			SBOM generation
SCREENSHOT_TESTING_DESC=	Screenshot testing

COMPOSE_TESTING_RUN_DEPENDS=		podman-compose:sysutils/podman-compose
MULTI_ARCH_MANIFESTS_RUN_DEPENDS=	skopeo:sysutils/skopeo
SBOM_RUN_DEPENDS=			trivy:security/trivy
SCREENSHOT_TESTING_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}scikit-image>=0:graphics/py-scikit-image@${PY_FLAVOR} \
					${PYTHON_PKGNAMEPREFIX}selenium>=0:www/py-selenium@${PY_FLAVOR} \
					chromium>=0:www/chromium

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
