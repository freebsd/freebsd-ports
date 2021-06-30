PORTNAME=	ansible
DISTVERSION=	4.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible-core>0:sysutils/py-ansible-core@${PY_FLAVOR}

USES=		ansible:env cpe python:3.6+ shebangfix
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

DO_MAKE_TEST=	ansible -m ping
TEST_TARGET=	localhost

_ANSIBLE_VERSIONS=	1 2 23 24 25 26 27 28
_ANSIBLE_PACKAGES=	${PYTHON_PKGNAMEPREFIX}ansible-*
.for version in ${_ANSIBLE_VERSIONS}
_ANSIBLE_PACKAGES+=	${PYTHON_PKGNAMEPREFIX}ansible${version}-*
.endfor

post-patch:
	${FIND} ${WRKSRC} -type f -exec ${GREP} --null -El '(/etc/ansible|/usr/share/ansible)' {} + | ${XARGS} -n 500 -0 ${REINPLACE_CMD} \
		-e 's|/etc/ansible|${ETCDIR}|g' \
		-e 's|/usr/share/ansible|${DATADIR}|g'
	${FIND} ${WRKSRC} -type f -name "*.bak" -delete

.include <bsd.port.mk>

# Make sure that we override the unique DATADIR and ETCDIR set
# by the implicit USES=uniquefiles.
DATADIR=	${ANSIBLE_DATADIR}
ETCDIR=		${ANSIBLE_ETCDIR}
