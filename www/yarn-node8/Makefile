# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node8

CONFLICTS_INSTALL=	yarn yarn-node10 yarn-node12

OPTIONS_EXCLUDE=	NODE NODE10 NODE12
OPTIONS_SLAVE=	NODE8

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
