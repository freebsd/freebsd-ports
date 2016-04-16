# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-socketmap

COMMENT=	Socketmap table support for opensmtpd

PLIST_FILES=	libexec/opensmtpd/table-socketmap \
		man/man5/table-socketmap.5.gz

CONFIGURE_ARGS=	--with-table-socketmap

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
