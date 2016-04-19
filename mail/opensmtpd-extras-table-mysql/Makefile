# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-mysql

COMMENT=	MySQL table support for opensmtpd

PLIST_FILES=	libexec/opensmtpd/table-mysql

CONFIGURE_ARGS=	--with-table-mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql

USE_MYSQL=	client

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
