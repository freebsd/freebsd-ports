PKGNAMESUFFIX=	-ldapdb

COMMENT=	SASL LDAPDB auxprop plugin
WWW=		https://www.cyrusimap.org/sasl/

CYRUS_CONFIGURE_ARGS=	--enable-ldapdb --with-ldap=${LOCALBASE}

USE_OPENLDAP=	yes

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
