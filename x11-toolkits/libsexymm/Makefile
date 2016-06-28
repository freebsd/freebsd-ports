# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	libsexymm
PORTVERSION=	0.1.9
PORTREVISION=	8
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexymm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ bindings for libsexy

LICENSE=	LGPL21

LIB_DEPENDS=	libsexy.so:x11-toolkits/libsexy \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		gmake pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
