PKGNAMESUFFIX=		-table-ldap
PORTREVISION=		1

COMMENT=		LDAP table support for OpenSMTPD

PLIST_FILES=		libexec/opensmtpd/table-ldap

CONFIGURE_ARGS+=	--with-table-ldap

USES=	ldap

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
