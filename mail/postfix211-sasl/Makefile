# $FreeBSD$

PKGNAMESUFFIX?=	211-sasl

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Postfix with Cyrus SASL support

MASTERDIR=	${.CURDIR}/../postfix211

OPTIONS_SLAVE=	SASL

SASL_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
