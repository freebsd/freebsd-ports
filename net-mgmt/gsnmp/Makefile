# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	gsnmp
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/local/${PORTNAME}/ \
		http://ftp-ext.osuosl.org/pub/nslu2/sources/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	SNMP library written on top of glib and gnet2

LIB_DEPENDS=	gnet:${PORTSDIR}/net/gnet2

USES=		pkgconfig
USE_GNOME=	gnomehack glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
