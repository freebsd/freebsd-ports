# New ports collection makefile for:    tapidbus
# Date created:		2006-01-11
# Whom:			Babak Farrokhi
#
# $FreeBSD$
#

PORTNAME=	tapidbus
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tapioca-voip

MAINTAINER=	babak@farrokhi.net
COMMENT=	Abstraction layer for interprocess communication

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig glib20 gnomehack
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|\-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
