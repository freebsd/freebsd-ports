# $FreeBSD$

PKGNAMESUFFIX=	-ldapdb

COMMENT=	SASL LDAPDB auxprop plugin

CYRUS_CONFIGURE_ARGS=	--enable-ldapdb --with-ldap=${LOCALBASE}

OPTIONS_DEFINE=		OPENLDAP_SASL
OPENLDAP_SASL_DESC=	OpenLDAP client with SASL2 support
OPENLDAP_SASL_VARS=	WANT_OPENLDAP_SASL=yes

USE_OPENLDAP=	yes
.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
