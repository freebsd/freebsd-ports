# $FreeBSD$

PKGNAMESUFFIX?=	-current-sasl

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Postfix with Cyrus SASL support

MASTERDIR=	${.CURDIR}/../postfix-current

OPTIONS_SLAVE=	SASL

SASL_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
