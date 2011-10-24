# New ports collection makefile for:	ecore-con
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	con
DISTVERSION=	1.0.1
CATEGORIES=	net enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (con module)

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_con
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-con

OPTIONS=	CARES	"Enable async DNS resolving via c-ares" on \
		CURL	"Enable Curl support"	on \
		SSL	"Enable SSL support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CARES)
CONFIGURE_ARGS+=	--enable-cares
LIB_DEPENDS+=		cares.2:${PORTSDIR}/dns/c-ares
.else
CONFIGURE_ARGS+=	--disable-cares
.endif

.if !defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=		curl.6:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if !defined(WITHOUT_SSL)
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
	${REINPLACE_CMD} 's/ openssl//' ${WRKSRC}/ecore-con.pc
	${INSTALL_DATA} ${WRKSRC}/ecore-con.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
