PORTNAME=	husky-areafix

COMMENT=	Husky FTN areafix library
WWW=		http://husky.sourceforge.net/

LICENSE=	LGPL20

LIB_DEPENDS=	libfidoconfig.so:news/husky-fidoconf \
		libhusky.so:news/husky-huskylib \
		libsmapi.so:news/husky-smapi

USE_LDCONFIG=	yes

MASTERDIR=	${.CURDIR}/../husky
COMPONENT_SUBDIR=	areafix

.include "${MASTERDIR}/Makefile"
