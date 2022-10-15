PORTNAME=	libg15
DISTVERSION=	3.0.7
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for control of LCD and the extra keys on Logitech keyboards
WWW=		https://gitlab.com/menelkir/libg15

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_ACCOUNT=	menelkir
GL_COMMIT=	ea3bc624ac7b3c84f4669c317cae8554ec897907

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
