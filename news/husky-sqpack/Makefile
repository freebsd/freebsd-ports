# $FreeBSD$

PORTNAME=	husky-sqpack

COMMENT=	Husky FTN msgbase packer

LICENSE=	GPLv2

LIB_DEPENDS=	libfidoconfig.so:news/husky-fidoconf \
		libhusky.so:news/husky-huskylib \
		libsmapi.so:news/husky-smapi

USE_LDCONFIG=	yes
PLIST_FILES=	bin/sqpack man/man1/sqpack.1.gz

MASTERDIR=	${.CURDIR}/../husky
COMPONENT_SUBDIR=	sqpack

post-patch:
	${REINPLACE_CMD} -e 's^/etc/fido/config^${PREFIX}/etc/fido/config^' \
		${BUILD_WRKSRC}/sqpack.1

.include "${MASTERDIR}/Makefile"
