# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node12

CONFLICTS_INSTALL=	yarn yarn-node10 yarn-node14

OPTIONS_EXCLUDE=	NODE NODE10 NODE14
OPTIONS_SLAVE=	NODE12

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
