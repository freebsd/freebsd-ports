PORTNAME=	gsnmp
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/local/${PORTNAME}/ \
		http://ftp-ext.osuosl.org/pub/nslu2/sources/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	SNMP library written on top of glib and gnet2
WWW=		https://trac.eecs.iu-bremen.de/projects/gsnmp/

LIB_DEPENDS=	libgnet-2.0.so:net/gnet2

USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
