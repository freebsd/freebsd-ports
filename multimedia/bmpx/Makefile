# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.12.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/bmpx/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Audio player

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		fam.0:${PORTSDIR}/devel/fam \
		xine.14:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_AUTOTOOLS=	libtool:15
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-xine --disable-gst
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAN1=		bmpx.1

post-extract:
	@${REINPLACE_CMD} -e 's|-Wall -pedantic -std=c99||' \
		${WRKSRC}/configure

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.1:${PORTSDIR}/devel/dbus
.endif

.include <bsd.port.mk>
