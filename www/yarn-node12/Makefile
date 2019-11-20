# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node12

CONFLICTS_INSTALL=	yarn yarn-node8 yarn-node10

OPTIONS_EXCLUDE=	NODE NODE6 NODE8 NODE10
OPTIONS_SLAVE=	NODE12

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
