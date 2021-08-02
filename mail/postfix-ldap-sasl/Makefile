PORTREVISION=	1
PKGNAMESUFFIX?=	-ldap-sasl

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Postfix with OpenLDAP and Cyrus SASL support

MASTERDIR=	${.CURDIR}/../postfix

OPTIONS_SLAVE=	LDAP LDAP_SASL SASL

SASL_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
