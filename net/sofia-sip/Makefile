PORTNAME=	sofia-sip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.9
CATEGORIES=	net

MAINTAINER=	jailbird@fdf.net
COMMENT=	Open-source SIP User-Agent library
WWW=		http://sofia-sip.sourceforge.net/

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
