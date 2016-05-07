# Created by: gahr
# $FreeBSD$

PKGNAMESUFFIX=	-table-passwd

COMMENT=	passwd(5) table support for opensmtpd

PLIST_FILES=	libexec/opensmtpd/table-passwd \
		man/man5/table-passwd.5.gz

CONFIGURE_ARGS=	--with-table-passwd
LDFLAGS+=	-L${LOCALBASE}/lib/mysql

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
