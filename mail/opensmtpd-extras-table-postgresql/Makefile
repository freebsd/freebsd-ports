# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-postgresql

COMMENT=	PostgreSQL table support for opensmtpd

PLIST_FILES=	libexec/opensmtpd/table-postgres

CONFIGURE_ARGS=	--with-table-postgres

USES=		pgsql

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
