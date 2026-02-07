VERSIONS=		120 121 122
# When changing this, remember to build test security/sssd with SMB=on
# Reference: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=244778
KRB5_VERSION?=		122

MASTERDIR=		${.CURDIR}/../krb5-${KRB5_VERSION}

FLAVORS=		default ldap

.include "${MASTERDIR}/Makefile"
