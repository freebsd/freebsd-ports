PORTNAME=	libg15render
PORTVERSION=	3.0.4
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/menelkir/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Library to render the LCD screen on Logitech keyboards

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libg15.so:sysutils/libg15

USES=		gmake libtool tar:bzip2 localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
