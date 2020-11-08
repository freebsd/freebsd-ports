# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node12

CONFLICTS_INSTALL=	npm npm-node10 npm-node14

OPTIONS_EXCLUDE=NODE NODE10 NODE14
OPTIONS_SLAVE=	NODE12

MASTERDIR=	${.CURDIR}/../npm

.include "${MASTERDIR}/Makefile"
