# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PKGNAMESUFFIX=	1
PORTVERSION=	1.9.6
PORTREVISION=	1

CONFLICTS=	ansible-* ansible23-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}

USES=	cpe python:2 shebangfix

PLIST_FILES=	man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz

SHEBANG_FILES=	lib/ansible/runner/action_plugins/synchronize.py

EXTRA_PATCHES=

DEPRECATED=		please upgrade to sysutils/ansible
EXPIRATION_DATE=	2017-10-01

.include "${MASTERDIR}/Makefile"
