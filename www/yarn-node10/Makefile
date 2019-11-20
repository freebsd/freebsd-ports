# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node10

CONFLICTS_INSTALL=	yarn yarn-node8 yarn-node12

OPTIONS_EXCLUDE=	NODE NODE8 NODE12
OPTIONS_SLAVE=	NODE10

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
