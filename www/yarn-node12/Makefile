# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-node12

DEPRECATED=	Uses EOL Python 2.7 via www/node12
EXPIRATION_DATE=2021-06-23

CONFLICTS_INSTALL=	yarn yarn-node10 yarn-node14

OPTIONS_EXCLUDE=	NODE NODE10 NODE14
OPTIONS_SLAVE=	NODE12

MASTERDIR=	${.CURDIR}/../yarn

.include "${MASTERDIR}/Makefile"
