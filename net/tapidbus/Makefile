# Created by: Babak Farrokhi
# $FreeBSD$

PORTNAME=	tapidbus
PORTVERSION=	0.2.1
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/tapioca-voip/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction layer for interprocess communication

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|\-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
