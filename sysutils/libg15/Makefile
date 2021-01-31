# $FreeBSD$

PORTNAME=	libg15
DISTVERSION=	1.2.8
CATEGORIES=	sysutils

MAINTAINER=	menelkir@itroll.org
COMMENT=	API for control of LCD and the extra keys on Logitech keyboards

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:gcc-c++11-lib gmake libtool tar:bzip2
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	menelkir
GL_COMMIT=	2c68e01a36c6c38dff03c42c8f86d6299b07c28a

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
