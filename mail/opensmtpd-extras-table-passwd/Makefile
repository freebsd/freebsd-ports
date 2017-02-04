# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-passwd
PORTREVISION=	1

COMMENT=	passwd(5) table support for OpenSMTPD

PLIST_FILES=	libexec/opensmtpd/table-passwd \
		man/man5/table-passwd.5.gz

CONFIGURE_ARGS+=	--with-table-passwd

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
