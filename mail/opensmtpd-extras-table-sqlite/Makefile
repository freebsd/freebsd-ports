# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-sqlite

COMMENT=	SQLite table support for opensmtpd

PLIST_FILES=	libexec/opensmtpd/table-sqlite \
		man/man5/table-sqlite.5.gz

CONFIGURE_ARGS=	--with-table-sqlite

USES=		sqlite

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
