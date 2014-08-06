# $FreeBSD$

PORTNAME=	husky-hpt
CATEGORIES=	news mail

MAINTAINER=	osharoiko@gmail.com
COMMENT=	Husky FTN tosser (development version)

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf-devel \
		libareafix.so:${PORTSDIR}/news/husky-areafix-devel

CONFLICTS=	husky-hpt-[0-9]*

ALL_TARGET=	all doc
INSTALL_TARGET=	install install-doc
INFO=		hpt

MASTERDIR=	${.CURDIR}/../husky-devel
COMPONENT_SUBDIR=       hpt

post-patch:
	${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hptlink.1
	${REINPLACE_CMD} -e 's^/some/path/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hpttree.1
	${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/txt2pkt.1

.include <bsd.port.mk>
