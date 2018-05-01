# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node4

CONFLICTS_INSTALL=	npm npm-node6 npm-node8 npm2 npm3 npm4

DEPRECATED=	Use www/npm instead
EXPIRATION_DATE=2018-05-31

OPTIONS_EXCLUDE=NODE NODE6 NODE8
OPTIONS_SLAVE=	NODE4

MASTERDIR=	${.CURDIR}/../npm

.include "${MASTERDIR}/Makefile"
