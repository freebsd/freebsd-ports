PORTNAME=	ansible
PORTVERSION?=	2.9.23
PORTREVISION?=	0
CATEGORIES=	sysutils python
MASTER_SITES=	http://releases.ansible.com/ansible/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=	2

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES?=		cpe gmake python:3.6+ shebangfix
CPE_VENDOR=	redhat
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_REGEX?=	[.]/test/.*[.]py

TEST_ARGS=	VERSION=${PORTVERSION} \
		PYTHON=${PYTHON_CMD} \
		DATE=
TEST_ENV=	PYTHON_VERSION=${PYTHON_VER}
TEST_TARGET=	tests

CONFLICTS_INSTALL=	${_ANSIBLE_PACKAGES:N${PKGBASE}-*}

EXTRA_PATCHES?=
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	MAJMINVER=${PORTVERSION:R} \
		PYTHON_PKGNAMEPREFIX=${PYTHON_PKGNAMEPREFIX} \
		PKGBASE=${PKGBASE}

PLIST_FILES?=	man/man1/ansible-config.1.gz \
		man/man1/ansible-console.1.gz \
		man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-inventory.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz
PORTEXAMPLES=	ansible.cfg hosts

_ANSIBLE_VERSIONS=	1 2 23 24 25 26 27 28
_ANSIBLE_PACKAGES=	${PYTHON_PKGNAMEPREFIX}ansible-*
.for version in ${_ANSIBLE_VERSIONS}
_ANSIBLE_PACKAGES+=	${PYTHON_PKGNAMEPREFIX}ansible${version}-*
.endfor

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e 's|/etc/ansible|${ETCDIR:S/${PY_FLAVOR}-//}|g' \
		-e 's|/usr/share/ansible|${DATADIR}|g'
	${FIND} ${WRKSRC} -type f -name "*.bak" -delete

	${REINPLACE_CMD} 's|"/etc"|"${PREFIX}/etc/"|g' ${WRKSRC}/test/units/playbook/test_helpers.py

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/bin -type l -name ansible-\* -lname ansible \
		-execdir ${RLN} ansible-${PYTHON_VER} {} \;
# python autoplist doesn't add this file in plist
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ansible_test/_data/injector/ansible-inventory

.include <bsd.port.mk>
