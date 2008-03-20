# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.12.2
PORTEPOCH=	1
CATEGORIES=	palm comms
MASTER_SITES=	http://www.mirrorservice.org/sites/master.us.finkmirrors.net/distfiles/ \
		http://katerina.frederic.k12.wi.us/mirror/pilot-link/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Suite of tools used to connect and sync your Palm handled

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GNOME=	gnometarget gnomehack pkgconfig
GNU_CONFIGURE=	yes
CFLAGS+=	-I${WRKSRC}/popt -I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-libiconv=${LOCALBASE}  --with-included-popt --enable-conduits
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:S/-Werror//}" # clear -Werror from CFLAGS
USE_LDCONFIG=	yes

OPTIONS=	PNG "build with png support" off \
		THREADS "built-in thread safety" on \
		USB "Compile with USB via libusb support (READ MANUAL!)" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads
CFLAGS+=		${PTHREAD_LIBS}
CONFIGURE_ENV+=		PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
.endif

.if defined(WITH_USB)
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=--enable-libusb
CONFIGURE_ENV+=LDFLAGS="${LDFLAGS} -L${PREFIX}/lib -lusb"

.if defined(WITHOUT_THREADS)
IGNORE=		cannot be built: USB support requires THREADS turned on.  Please reconfigure using 'make config'
.else
LDFLAGS+=	${PTHREAD_LIBS}
.endif
.endif

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng=${PREFIX}
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.include "${.CURDIR}/manpages.mk"

post-patch:
.if !defined(WITHOUT_THREADS)
	@${REINPLACE_CMD} -e 's|Libs: |Libs: ${PTHREAD_LIBS} |' ${WRKSRC}/pilot-link.pc.in ${WRKSRC}/pilot-link-pp.pc.in
.endif

.include <bsd.port.post.mk>
