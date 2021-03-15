# $FreeBSD$

PORTNAME=	libg15render
PORTVERSION=	3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/menelkir/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	menelkir@itroll.org
COMMENT=	Library to render the LCD screen on Logitech keyboards

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libg15.so:sysutils/libg15

USES=		compiler:gcc-c++11-lib gmake libtool tar:bzip2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
