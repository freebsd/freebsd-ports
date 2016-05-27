# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-sqlite
PORTREVISION=	1

COMMENT=	SQLite table support for OpenSMTPD

PLIST_FILES=	libexec/opensmtpd/table-sqlite \
		man/man5/table-sqlite.5.gz

CONFIGURE_ARGS+=	--with-table-sqlite

USES=		sqlite pkgconfig

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
