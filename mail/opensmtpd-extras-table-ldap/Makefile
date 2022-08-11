PKGNAMESUFFIX=		-table-ldap
PORTREVISION=		1

COMMENT=		LDAP table support for OpenSMTPD

PLIST_FILES=		libexec/opensmtpd/table-ldap

CONFIGURE_ARGS+=	--with-table-ldap

USE_OPENLDAP=		client

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
