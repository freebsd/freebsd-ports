# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node10

CONFLICTS_INSTALL=	npm npm-node12 npm-node8

OPTIONS_EXCLUDE=NODE NODE12 NODE8
OPTIONS_SLAVE=	NODE10

MASTERDIR=	${.CURDIR}/../npm

.include "${MASTERDIR}/Makefile"
