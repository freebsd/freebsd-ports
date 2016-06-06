# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-scheduler-python
PORTREVISION=		0

COMMENT=		Python scheduler support for OpenSMTPD
MAINTAINER=		fluffy@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/scheduler-python

CONFIGURE_ARGS+=	--with-scheduler-python --with-python-type=${PYTHON_VERSION}

USES=			python pkgconfig

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
