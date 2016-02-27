# $FreeBSD$

PKGNAMESUFFIX=	-ldapdb
PORTREVISION=	5

COMMENT=	SASL LDAPDB auxprop plugin

USE_OPENLDAP=	yes
.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

CONFIGURE_ARGS+=--enable-ldapdb --with-ldap=${LOCALBASE}

PLIST_FILES=	lib/sasl2/libldapdb.a \
		lib/sasl2/libldapdb.so \
		lib/sasl2/libldapdb.so.3 \
		lib/sasl2/libldapdb.so.3.0.0

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
