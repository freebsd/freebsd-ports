# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node10

CONFLICTS_INSTALL=	yarn yarn-node12 yarn-node14

OPTIONS_EXCLUDE=	NODE NODE12 NODE14
OPTIONS_SLAVE=	NODE10

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
