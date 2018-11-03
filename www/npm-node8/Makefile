# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node8

CONFLICTS_INSTALL=	npm npm-node10 npm-node6

OPTIONS_EXCLUDE=NODE NODE10 NODE6
OPTIONS_SLAVE=	NODE8

MASTERDIR=	${.CURDIR}/../npm

.include "${MASTERDIR}/Makefile"
