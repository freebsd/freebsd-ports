# $FreeBSD$

PORTNAME=	husky-htick
CATEGORIES=	news mail

MAINTAINER=     osharoiko@gmail.com
COMMENT=	Husky FTN file ticker

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf \
		libareafix.so:${PORTSDIR}/news/husky-areafix

ALL_TARGET=	all doc
INSTALL_TARGET=	install install-doc
INFO=		htick
USE_LDCONFIG=   yes

MASTERDIR=      ${.CURDIR}/../husky
COMPONENT_SUBDIR=       htick

post-patch:
	${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/htick.1

.include <bsd.port.mk>
