# $FreeBSD$

PORTNAME=	libg15
PORTVERSION=	1.2.7
CATEGORIES=	sysutils
MASTER_SITES=	SF/g15tools/libg15/${PORTVERSION}

MAINTAINER=	menelkir@itroll.org
COMMENT=	API for control of LCD and the extra keys on Logitech keyboards

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:gcc-c++11-lib gmake libtool tar:bzip2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
