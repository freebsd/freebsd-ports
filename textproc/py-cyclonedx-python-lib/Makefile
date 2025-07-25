PORTNAME=	cyclonedx-python-lib
PORTVERSION=	10.5.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://github.com/CycloneDX/cyclonedx-python-lib/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cyclonedx_python_lib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for producing CycloneDX SBOM (Software Bill of Materials) files
WWW=		https://github.com/CycloneDX/cyclonedx-python-lib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}license-expression>=30<31:textproc/py-license-expression@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packageurl-python>=0.11<2:textproc/py-packageurl-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-serializable>=2.0.0<3:devel/py-py-serializable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.4.0<3:devel/py-sortedcontainers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	JSON_VALIDATION VALIDATION XML_VALIDATION
JSON_VALIDATION_DESC=	JSON validation
VALIDATION_DESC=	JSON and XML validation
VALIDATION_IMPLIES=	JSON_VALIDATION XML_VALIDATION
XML_VALIDATION_DESC=	XML validation

JSON_VALIDATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.25<5:devel/py-jsonschema@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}referencing>=0.28.4:devel/py-referencing@${PY_FLAVOR}
# jsonschema[format-nongpl]
JSON_VALIDATION_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fqdn>=0:www/py-fqdn@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}isoduration>=0:devel/py-isoduration@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}jsonpointer>=1.13:devel/py-jsonpointer@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}rfc3339-validator>=0:devel/py-rfc3339-validator@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}rfc3986-validator>=0.1.0:devel/py-rfc3986-validator@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}rfc3987-syntax>=1.1.0:www/py-rfc3987-syntax@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}uri-template>=0:net/py-uri-template@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}webcolors>=24.6.0:graphics/py-webcolors@${PY_FLAVOR}
XML_VALIDATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4<7:devel/py-lxml5@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6<5:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
