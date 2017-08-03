# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	net lang
PKGNAMESUFFIX=	-ldap

COMMENT=	Free Pascal interface to OpenLDAP

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENLDAP
OPENLDAP_DESC=	Install OpenLDAP libraries
OPTIONS_DEFAULT=	OPENLDAP

OPENLDAP_USE=	OPENLDAP=yes

.include "${MASTERDIR}/Makefile"
