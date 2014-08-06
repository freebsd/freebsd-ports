# $FreeBSD$

PORTNAME=	husky-smapi
CATEGORIES=	news mail

MAINTAINER=	osharoiko@gmail.com
COMMENT=	Husky FTN MSGAPI library (development version)

LIB_DEPENDS=    libhusky.so:${PORTSDIR}/news/husky-huskylib-devel

CONFLICTS=	husky-smapi-[0-9]*

USE_LDCONFIG=	yes

MASTERDIR=	${.CURDIR}/../husky-devel
COMPONENT_SUBDIR=	smapi

.include <bsd.port.mk>
