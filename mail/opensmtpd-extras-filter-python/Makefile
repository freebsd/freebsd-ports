# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-filter-python
PORTREVISION=		0

COMMENT=		Python-script filter support for OpenSMTPD
MAINTAINER=		fluffy@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-python

CONFIGURE_ARGS+=	--with-filter-python --with-python-type=${PYTHON_VERSION}

USES=			python:2 pkgconfig

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
