# New ports collection makefile for:	telepathy-salut
# Date created:				Apr 16 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	telepathy-salut
PORTVERSION=	0.1.3
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

LIB_PC_DEPENDS=	gobject-2.0.pc:${PORTSDIR}/devel/glib20 \
		avahi-glib.pc:${PORTSDIR}/net/avahi \
		telepathy-glib.pc:${PORTSDIR}/net-im/telepathy-glib

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${GMAKE} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in \
		${WRKSRC}/lib/gibber/examples/Makefile.in

.include <bsd.port.mk>
