# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node12

CONFLICTS_INSTALL=	npm npm-node8 npm-node10

OPTIONS_EXCLUDE=NODE NODE10 NODE8
OPTIONS_SLAVE=	NODE12

MASTERDIR=	${.CURDIR}/../npm

.include "${MASTERDIR}/Makefile"
