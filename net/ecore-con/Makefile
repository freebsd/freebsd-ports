# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	con
PORTVERSION=	1.7.8
CATEGORIES=	net enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (con module)

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_con
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-con

OPTIONS_DEFINE=	CARES CURL SSL
OPTIONS_DEFAULT=CARES CURL SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCARES}
CONFIGURE_ARGS+=	--enable-cares
LIB_DEPENDS+=		libcares.so:${PORTSDIR}/dns/c-ares
.else
CONFIGURE_ARGS+=	--disable-cares
.endif

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=		libcurl.so:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ENV=		SSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" SSL_LIBS="-lssl"
CONFIGURE_ARGS+=	--enable-openssl
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	@${REINPLACE_CMD} 's/ openssl//' ${WRKSRC}/ecore-con.pc
	${INSTALL_DATA} ${WRKSRC}/ecore-con.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
