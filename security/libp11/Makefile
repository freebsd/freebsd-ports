# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libp11
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security devel

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Small layer on top of PKCS\#11 API

LICENSE=	LGPL21

LIB_DEPENDS=	libltdl.so:devel/libltdl

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_GITHUB=	yes
GH_ACCOUNT=	OpenSC

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

CONFIGURE_ARGS=	--with-enginesdir=${PREFIX}/lib/engines

INSTALL_TARGET=	install-strip

PORTDOCS=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/Makefile ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
