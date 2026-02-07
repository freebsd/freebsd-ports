PORTNAME=	stoken
DISTVERSIONPREFIX=	v
DISTVERSION=	0.93
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Software Token for UNIX compatible with RSA SecurID
WWW=		https://sourceforge.net/p/stoken/wiki/Home/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt # can alternatively use nettle, potentially port option can be created

USES=		gnome libtool localbase pkgconfig autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	stoken-dev
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS X11
OPTIONS_SUB=	yes

X11_CONFIGURE_WITH=	gtk
X11_DESC=	Build GUI token interface
X11_USE=	GNOME=gtk30,cairo,gdkpixbuf
X11_USES=	desktop-file-utils

do-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
