PKGNAMESUFFIX=	-table-socketmap
PORTREVISION=	1

COMMENT=	Socketmap table support for OpenSMTPD

PLIST_FILES=	libexec/opensmtpd/table-socketmap \
		share/man/man5/table-socketmap.5.gz

CONFIGURE_ARGS+=	--with-table-socketmap

MASTERDIR=	${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"
