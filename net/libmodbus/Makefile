PORTNAME=	libmodbus
DISTVERSION=	3.2.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/stephane/libmodbus/releases/download/v${DISTVERSION}/

MAINTAINER=	ing.castellanosdz@gmail.com
COMMENT=	Modbus library for GNU/Linux, Mac OS, FreeBSD and Windows
WWW=		https://libmodbus.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	AUTHORS NEWS.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
