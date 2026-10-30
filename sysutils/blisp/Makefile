PORTNAME=	blisp
DISTVERSION=	g20250802
CATEGORIES=	sysutils

MAINTAINER=	bsd@orsolic.org
COMMENT=	Utility and library for flashing Bouffalo RISC-V MCUs
WWW=		https://github.com/pine64/blisp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libserialport.so:devel/libserialport

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	pine64
GH_TAGNAME=	b1d9a69
GH_TUPLE=	argtable:argtable3:b50c6c8:group_argtable/vendor/argtable3

PLIST_FILES=	bin/blisp \
		etc/devd/blisp.conf

CMAKE_ON=	BLISP_BUILD_CLI

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/tools/blisp/blisp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} files/devd-blisp.conf ${STAGEDIR}${PREFIX}/etc/devd/blisp.conf

.include <bsd.port.mk>
