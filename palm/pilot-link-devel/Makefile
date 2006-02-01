# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
DISTVERSION=	0.12.0-pre4
CATEGORIES=	palm comms
MASTER_SITES=	http://katerina.frederic.k12.wi.us/mirror/pilot-link/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Suite of tools used to connect and sync your Palm handled

USE_ICONV=	yes
USE_GETOPT_LONG=yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libiconv=${LOCALBASE}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS:S/-Werror//}" # clear -Werror from CFLAGS

OPTIONS=	PNG "build with png support" off\
		THREADS "built-in thread safety" on\

PLIST_SUB+=	PKGCONFIG_DIR=${PKGCONFIG_DIR}

.include "${.CURDIR}/manpages.mk"
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgconfigdir = .*$$,pkgconfigdir = ${PREFIX}/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.in

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads
LDFLAGS+=	${PTHREAD_LIBS}
.endif

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng=${PREFIX}
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.include <bsd.port.post.mk>
