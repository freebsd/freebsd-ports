# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PKGNAMESUFFIX=	1
PORTVERSION=	1.9.6
PORTREVISION=	1

CONFLICTS=	ansible-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}paramiko1>0:security/py-paramiko1 \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2

USES=	cpe python:2 shebangfix

SHEBANG_FILES=	lib/ansible/runner/action_plugins/synchronize.py

EXTRA_PATCHES=

DEPRECATED=		please upgrade to sysutils/ansible
EXPIRATION_DATE=	2016-10-01

.include "${MASTERDIR}/Makefile"
