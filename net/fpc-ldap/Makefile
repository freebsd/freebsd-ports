# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-ldap

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to OpenLDAP

USE_FPC=	hash

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENLDAP
OPENLDAP_DESC=	Install OpenLDAP libraries
OPTIONS_DEFAULT=	OPENLDAP

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
