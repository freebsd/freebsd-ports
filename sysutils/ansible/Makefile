PORTNAME=	ansible
DISTVERSION=	11.7.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Radically simple IT automation
WWW=		https://www.ansible.com/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible-core>0:sysutils/py-ansible-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR}

USES=		ansible:env cpe python:3.10+ shebangfix
CPE_VENDOR=	redhat
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	ansible_collections/ovirt/ovirt/roles/disaster_recovery/files/ovirt-dr
# It's probably best to leave shebangs in modules untouched as they must be
# either unversioned or absent.
# See [1] and [2].
# [1]: https://github.com/ansible/ansible/issues/78243
# [2]: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265211
SHEBANG_REGEX=	(([^/])|(/[^m])|(/m[^o])|(/mo[^d])|(/mod[^u])|(/modu[^l])|(/modul[^e])|(/module[^s])|(/modules[^/]))*\.(py|sh|build.py.generic)
python_OLD_CMD=	/Users/kbreit/Documents/Programming/ansible_collections/cisco/meraki/venv/bin/python

NO_ARCH=	yes

DO_MAKE_TEST=	env LC_ALL=C.UTF-8 ansible -m ping
TEST_TARGET=	localhost

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
