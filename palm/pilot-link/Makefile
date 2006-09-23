# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
DISTVERSION=	0.12.1
PORTEPOCH=	1
CATEGORIES=	palm comms
MASTER_SITES=	http://www.mirrorservice.org/sites/master.us.finkmirrors.net/distfiles/ \
		http://katerina.frederic.k12.wi.us/mirror/pilot-link/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Suite of tools used to connect and sync your Palm handled

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GETOPT_LONG=yes
USE_GNOME=	gnometarget gnomehack
GNU_CONFIGURE=	yes
CFLAGS+=	-I${WRKSRC}/popt -I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-libiconv=${LOCALBASE}  --with-included-popt --enable-conduits \
		 --mandir=${MANPREFIX}/man
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:S/-Werror//}" # clear -Werror from CFLAGS
USE_LDCONFIG=	yes

OPTIONS=	PNG "build with png support" off \
		THREADS "built-in thread safety" on \
		USB "Compile with USB via libusb support (READ MANUAL!)" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads
LDFLAGS+=	${PTHREAD_LIBS}
.endif

.if defined(WITH_USB)
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=--enable-libusb
CONFIGURE_ENV+="LDFLAGS=${LDFLAGS} -L${PREFIX}/lib -lusb"
.endif

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng=${PREFIX}
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.include "${.CURDIR}/manpages.mk"

.include <bsd.port.post.mk>
