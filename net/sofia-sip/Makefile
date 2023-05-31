PORTNAME=	sofia-sip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.15
CATEGORIES=	net

MAINTAINER=	jailbird@fdf.net
COMMENT=	Open-source SIP User-Agent library
WWW=		https://github.com/freeswitch/sofia-sip/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake gnome libtool pathfix pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	freeswitch

USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_SUB+=	VER=${DISTVERSION:R}

.include <bsd.port.mk>
