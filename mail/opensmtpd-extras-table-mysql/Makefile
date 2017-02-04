# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-mysql
PORTREVISION=	1

COMMENT=	MySQL table support for OpenSMTPD

PLIST_FILES=	libexec/opensmtpd/table-mysql

CONFIGURE_ARGS+=	--with-table-mysql
CFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql

USES=		mysql

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
