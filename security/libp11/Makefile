PORTNAME=	libp11
PORTVERSION=	0.4.14
PORTREVIION=	1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security devel

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Small layer on top of PKCS\#11 API
WWW=		https://github.com/OpenSC/libp11/wiki

LICENSE=	LGPL21

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf cpe libtool pkgconfig ssl
CPE_VENDOR=	opensc_project
CPE_PRODUCT=	opensc

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES

DOXYGEN_CONFIGURE_ENABLE=	api-doc
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_USES=		gmake
DOXYGEN_IMPLIES=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	OpenSC

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

CONFIGURE_ARGS=	--with-enginesdir=${PREFIX}/lib/engines \
		--with-modulesdir=${PREFIX}/lib/ossl-modules \
		--enable-static-engine

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == "base" && ${OPSYS} == FreeBSD && ${OSREL:R} < 14
PLIST_SUB+=		PROVIDERS="@comment "
.else
PLIST_SUB+=		PROVIDERS=""
.endif


INSTALL_TARGET=	install-strip

PORTDOCS=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/Makefile ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
