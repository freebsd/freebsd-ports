# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-python

COMMENT=	Python table support for opensmtpd

PLIST_FILES=	libexec/opensmtpd/table-python

CONFIGURE_ARGS=	--with-table-python --with-python-type=${PYTHON_VERSION}

USES=		python

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
