# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	net6
PORTVERSION=	1.3.14
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://releases.0x539.de/net6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network access framework for IPv4/IPv6

LICENSE=	GPLv2

LIB_DEPENDS=	libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libgnutls.so:${PORTSDIR}/security/gnutls

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
