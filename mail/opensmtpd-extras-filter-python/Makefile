# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-filter-python
PORTREVISION=		0

COMMENT=		Python-script filter support for OpenSMTPD

PLIST_FILES=		libexec/opensmtpd/filter-python

CONFIGURE_ARGS+=	--with-experimental-filter-python --with-python-type=${PYTHON_VERSION}

USES=			python:2 pkgconfig

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
