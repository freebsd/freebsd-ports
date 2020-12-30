# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node14

CONFLICTS_INSTALL=	yarn yarn-node10 yarn-node12

OPTIONS_EXCLUDE=	NODE NODE10 NODE12
OPTIONS_SLAVE=	NODE14

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
