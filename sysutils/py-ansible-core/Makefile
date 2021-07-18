PORTNAME=	ansible-core
DISTVERSION=	2.11.2
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resolvelib05>=0.5.3<0.6:devel/py-resolvelib05@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		ansible:env cpe gmake python:3.6+ shebangfix
CPE_VENDOR=	redhat
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_REGEX=	[.]/test/.*[.]py

TEST_ARGS=	VERSION=${DISTVERSION} \
		PYTHON=${PYTHON_CMD} \
		DATE=
TEST_ENV=	PYTHON_VERSION=${PYTHON_VER}
TEST_TARGET=	tests

CONFLICTS=	py*-ansible-base

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/ansible-config.1.gz \
		share/man/man1/ansible-console.1.gz \
		share/man/man1/ansible-doc.1.gz \
		share/man/man1/ansible-galaxy.1.gz \
		share/man/man1/ansible-inventory.1.gz \
		share/man/man1/ansible-playbook.1.gz \
		share/man/man1/ansible-pull.1.gz \
		share/man/man1/ansible-vault.1.gz \
		share/man/man1/ansible.1.gz
PORTEXAMPLES=	ansible.cfg hosts

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
# Preserve the original paths in
# test/units/cli/galaxy/test_execute_list_collection.py.
# Replacing /usr/share/ansible breaks tests.
	${FIND} ${WRKSRC} -not -regex '${WRKSRC}/test/units/cli/galaxy/test_execute_list_collection.py' -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} \
			-e 's|/etc/ansible|${ETCDIR}|g' \
			-e 's|/usr/share/ansible|${DATADIR}|g'
	${FIND} ${WRKSRC} -type f -name "*.bak" -delete

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/bin -type l -name ansible-\* -lname ansible \
		-execdir ${RLN} ansible-${PYTHON_VER} {} \;
# USE_PYTHON=autoplist doesn't add this file to pkg-plist.
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ansible_test/_data/injector/ansible-inventory

pre-test:
# This one file does not get its paths replaced correctly in post-patch.
	${REINPLACE_CMD} 's|"/etc"|"${ETCDIR:H}"|g' \
		${WRKSRC}/test/units/playbook/test_helpers.py
# This test constructs a Python script inline and uses an invalid path to it.
	${REINPLACE_CMD} 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/test/units/modules/test_async_wrapper.py
# Skip the SELinux tests, it's not present on FreeBSD.
	${RM} ${WRKSRC}/test/units/module_utils/basic/test_selinux.py
# Disable some failing tests. They fail to detect that emoji are of width 2 istead of 1.
	${RM} ${WRKSRC}/test/units/utils/test_display.py

.include <bsd.port.mk>

# Make sure that we override the unique DATADIR and ETCDIR set
# by the implicit USES=uniquefiles.
DATADIR=	${ANSIBLE_DATADIR}
ETCDIR=		${ANSIBLE_ETCDIR}
