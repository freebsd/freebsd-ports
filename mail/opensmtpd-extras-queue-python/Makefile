# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-queue-python
PORTREVISION=		0

COMMENT=		Python queue support for OpenSMTPD

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

PLIST_FILES=		libexec/opensmtpd/queue-python

CONFIGURE_ARGS+=	--with-queue-python --with-python-type=${PYTHON_VERSION}

USES=			python:2.7 pkgconfig

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
