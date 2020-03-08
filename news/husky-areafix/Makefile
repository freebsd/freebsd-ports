# $FreeBSD$

PORTNAME=	husky-areafix

COMMENT=	Husky FTN areafix library

LICENSE=	LGPL20

LIB_DEPENDS=	libfidoconfig.so:news/husky-fidoconf \
		libhusky.so:news/husky-huskylib \
		libsmapi.so:news/husky-smapi

USE_LDCONFIG=	yes

MASTERDIR=	${.CURDIR}/../husky
COMPONENT_SUBDIR=	areafix

.include "${MASTERDIR}/Makefile"
