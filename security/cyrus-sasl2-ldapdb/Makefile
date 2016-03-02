# $FreeBSD$

PKGNAMESUFFIX=	-ldapdb
PORTREVISION=	5

COMMENT=	SASL LDAPDB auxprop plugin

CYRUS_CONFIGURE_ARGS=	--enable-ldapdb --with-ldap=${LOCALBASE}

USE_OPENLDAP=	yes
.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
