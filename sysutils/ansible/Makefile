PORTNAME=	ansible
DISTVERSION=	3.3.0
CATEGORIES=	sysutils python
MASTER_SITES=	http://releases.ansible.com/ansible/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible-base>0:sysutils/py-ansible-base@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		cpe gmake python:3.6+ shebangfix
CPE_VENDOR=	redhat
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	ansible_collections/community/zabbix/roles/zabbix_proxy/files/install_semodule.bsx \
		ansible_collections/community/zabbix/roles/zabbix_server/files/install_semodule.bsx \
		ansible_collections/cyberark/conjur/ci/build_release \
		ansible_collections/cyberark/conjur/ci/publish_to_galaxy \
		ansible_collections/ovirt/ovirt/roles/disaster_recovery/files/ovirt-dr
SHEBANG_GLOB=	*.py *.sh

CONFLICTS_INSTALL=	${_ANSIBLE_PACKAGES:N${PKGBASE}-*}

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_PKGNAMEPREFIX=${PYTHON_PKGNAMEPREFIX}

_ANSIBLE_VERSIONS=	1 2 23 24 25 26 27 28
_ANSIBLE_PACKAGES=	${PYTHON_PKGNAMEPREFIX}ansible-*
.for version in ${_ANSIBLE_VERSIONS}
_ANSIBLE_PACKAGES+=	${PYTHON_PKGNAMEPREFIX}ansible${version}-*
.endfor

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${FIND} ${WRKSRC} -type f -exec grep --null -El '(/etc/ansible|/usr/share/ansible)' | ${XARGS} -0 ${REINPLACE_CMD} \
		-e 's|/etc/ansible|${ETCDIR:S/${PY_FLAVOR}-//}|g' \
		-e 's|/usr/share/ansible|${DATADIR}|g'
	${FIND} ${WRKSRC} -type f -name "*.bak" -delete

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/bin -type l -name ansible-\* -lname ansible \
		-execdir ${RLN} ansible-${PYTHON_VER} {} \;
# python autoplist doesn't add this file in plist
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ansible_test/_data/injector/ansible-inventory

.include <bsd.port.mk>
