# New ports collection makefile for:	ecore-con
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	con
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (con module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_GETOPT_LONG=yes
USE_EFL=	ecore
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_con
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--enable-ecore-con \
		--disable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--disable-ecore-file \
		--disable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--disable-ecore-x \
		--disable-ecore-imf \
		--disable-ecore-imf_evas

OPTIONS=	CURL	"Enable Curl support"	on \
		SSL	"Enable SSL support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=		curl.4:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if !defined(WITHOUT_SSL)
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
	${INSTALL_DATA} ${WRKSRC}/ecore-con.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
