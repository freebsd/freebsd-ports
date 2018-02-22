# Created by: Pietro Cerutti <gahr@gahr.ch>
# $FreeBSD$

PORTNAME=	scew
PORTVERSION=	1.1.9
CATEGORIES=	textproc
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple C Expat Wrapper

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

OPTIONS_DEFINE=	TEST
.if defined(MAINTAINER_MODE)
OPTIONS_DEFAULT=TEST
.endif

USES=		gmake libtool localbase pathfix pkgconfig
CONFIGURE_ARGS=	enable_tests=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

TEST_LIB_DEPENDS=	libcheck.so:devel/check
TEST_VARS=		TEST_TARGET=check TEST_WRKSRC=${WRKSRC}/tests

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/scew_print/scew_print ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/scew_stream/scew_stream ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/scew_write/scew_write ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
