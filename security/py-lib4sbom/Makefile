PORTNAME=	lib4sbom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Software bill of material (SBOM) generator and consumer library
WWW=		https://github.com/anthonyharrison/lib4sbom

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.8<3:devel/py-semantic-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmlschema>0:textproc/py-xmlschema@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	anthonyharrison
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_BROKEN_TESTS=	test_set_checksum test_set_type test_set_supplier \
			test_set_originator test_set_downloadlocation \
			test_set_homepage test_set_checksum \
			test_set_checksum_multiple test_set_externalreference \
			test_set_checksum test_set_type test_set_supplier \
			test_set_originator test_set_downloadlocation \
			test_set_homepage test_set_checksum \
			test_set_checksum_multiple test_set_externalreference
# There is blank tests are are not implemented yet
PYTEST_IGNORED_TESTS=	test_store test_getBOM test_generateTime \
			test_generateDocumentHeader \
			test_generateJSONDocumentHeader \
			test_generateXMLDocumentHeader \
			test_generateRelationship test_generateComponent \
			test_generateJSONComponent test_generateXMLComponent \
			test_parse test_parse_cyclonedx_json test_get_format \
			test_get_type test_generate test_get_sbom \
			test_generate_spdx test_get_spdx test_get_relationships \
			test_get_cyclonedx test_generate_cyclonedx test_close \
			test_file_out test_console_out test_show \
			test_format_json_data test_format_yaml_data \
			test_format_tag_data test_send_output \
			test_generate_output test_parse_file test_get_type \
			test_get_files test_get_packages test_get_relationships \
			test_show test_getBOM test_getRelationships \
			test_generateTag test_generateComment test_generateTime \
			test_generateTagDocumentHeader \
			test_generateJSONDocumentHeader \
			test_generateDocumentHeader test_package_ident \
			test_file_ident test_license_ident \
			test_generateTagPackageDetails \
			test_generateJSONPackageDetails \
			test_generateTagFileDetails \
			test_generateJSONFileDetails \
			test_generatePackageDetails test_generateFileDetails \
			test_generateRelationship test_showRelationship \
			test_parse test_parse_spdx_tag test_parse_spdx_json \
			test_parse_spdx_rdf test_parse_spdx_yaml \
			test_parse_spdx_xml

NO_ARCH=	YES

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${MV} ${WRKSRC}/test ${WRKSRC}/${PORTNAME}
	${MV} ${WRKSRC}/tools ${WRKSRC}/${PORTNAME}

post-patch-EXAMPLES-off:
	@${RM} -r ${WRKSRC}/examples

post-stage-EXAMPLES-on:
	${RM} -r ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/examples
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${REINPLACE_CMD} -e '/\/examples\//d' \
		${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
