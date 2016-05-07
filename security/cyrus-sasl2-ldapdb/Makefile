# $FreeBSD$

PKGNAMESUFFIX=	-ldapdb
PORTREVISION=	5

COMMENT=	SASL LDAPDB auxprop plugin

OPTIONS_DEFINE=		OPENLDAP_SASL
OPENLDAP_SASL_DESC=	OpenLDAP client with SASL2 support
OPENLDAP_SASL_VARS=	WANT_OPENLDAP_SASL=yes

CYRUS_CONFIGURE_ARGS=	--enable-ldapdb --with-ldap=${LOCALBASE}

USE_OPENLDAP=	yes
.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
