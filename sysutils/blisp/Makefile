PORTNAME=	blisp
DISTVERSION=	g20230703
CATEGORIES=	sysutils

MAINTAINER=	porsolic@gmail.com
COMMENT=	Utility and library for flashing Bouffalo RISC-V MCUs
WWW=		https://github.com/pine64/blisp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libserialport.so:devel/libserialport

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	pine64
GH_TAGNAME=	048a724
GH_TUPLE=	argtable:argtable3:6f0e40b:group_argtable/vendor/argtable3

PLIST_FILES=	bin/blisp \
		etc/devd/blisp.conf

CMAKE_ON=	BLISP_BUILD_CLI

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/tools/blisp/blisp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} files/devd-blisp.conf ${STAGEDIR}${PREFIX}/etc/devd/blisp.conf

.include <bsd.port.mk>
