PORTNAME=	sofia-sip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.3
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source SIP User-Agent library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake gnome libtool pathfix pkgconfig ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	freeswitch

GNU_CONFIGURE=	yes

PLIST_SUB+=	VER=${DISTVERSION:R}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
