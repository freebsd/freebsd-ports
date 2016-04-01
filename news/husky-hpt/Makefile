# $FreeBSD$

PORTNAME=	husky-hpt

COMMENT=	Husky FTN tosser

LIB_DEPENDS=	libfidoconfig.so:news/husky-fidoconf \
		libareafix.so:news/husky-areafix

USES+=		makeinfo
ALL_TARGET=	all doc
INSTALL_TARGET=	install install-doc
INFO=		hpt

MASTERDIR=	${.CURDIR}/../husky
COMPONENT_SUBDIR=       hpt

post-patch:
	${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hptlink.1
	${REINPLACE_CMD} -e 's^/some/path/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hpttree.1
	${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/txt2pkt.1

.include "${MASTERDIR}/Makefile"
