# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-python
PORTREVISION=	0

COMMENT=	Python table support for OpenSMTPD

PLIST_FILES=	libexec/opensmtpd/table-python

CONFIGURE_ARGS+=	--with-table-python --with-python-type=${PYTHON_VERSION}

USES=		python pkgconfig

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
