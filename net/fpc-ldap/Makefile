# New ports collection makefile for:	fpc-ldap
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	net lang
PKGNAMESUFFIX=	-ldap

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to OpenLDAP

USE_FPC=	hash

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	OPENLDAP	"Install OpenLDAP libraries"	on

.include "${MASTERDIR}/Makefile"
