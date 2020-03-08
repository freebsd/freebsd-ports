# $FreeBSD$

PORTNAME=	husky-hpt

COMMENT=	Husky FTN tosser

LICENSE=	GPLv2

LIB_DEPENDS=	libareafix.so:news/husky-areafix \
		libfidoconfig.so:news/husky-fidoconf \
		libhusky.so:news/husky-huskylib \
		libsmapi.so:news/husky-smapi

USES+=		makeinfo perl5
ALL_TARGET=	all doc
INSTALL_TARGET=	install install-doc
INFO=		hpt

MASTERDIR=	${.CURDIR}/../husky
COMPONENT_SUBDIR=hpt
MAKE_ARGS=	INFODIR=${PREFIX}/${INFO_PATH}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${BUILD_WRKSRC}/man/hptlink.1
	${REINPLACE_CMD} -e 's^/some/path/config^${PREFIX}/etc/fido/config^' \
		${BUILD_WRKSRC}/man/hpttree.1
	${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${BUILD_WRKSRC}/man/txt2pkt.1

.include "${MASTERDIR}/Makefile"
