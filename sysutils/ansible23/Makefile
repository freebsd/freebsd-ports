# $FreeBSD$

PORTVERSION=	2.3.3.0
PORTREVISION=	5
PKGNAMESUFFIX=	23

CONFLICTS=	ansible-* \
		ansible1-* \
		ansible24-* \
		ansible25-* \
		ansible26-* \
		ansible27-* \
		ansible28-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

DEPRECATED=	Upstream support ended. Consider upgrading to sysutils/ansible
EXPIRATION_DATE=2020-05-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

PLIST_FILES=	man/man1/ansible-console.1.gz \
		man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz

USES=		cpe python
EXTRA_PATCHES=

.include "${MASTERDIR}/Makefile"
