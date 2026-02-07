PORTNAME=	libg15render
DISTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to render the LCD screen on Logitech keyboards
WWW=		https://gitlab.com/menelkir/libg15render

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libg15.so:sysutils/libg15

USES=		gmake libtool localbase
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_ACCOUNT=	menelkir
GL_TAGNAME=	b7c1b217e95a1c473fa219c1940c8c9db0eb4628

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
