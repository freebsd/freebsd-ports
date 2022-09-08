PORTNAME=	libg15
DISTVERSION=	3.0.7
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/menelkir/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for control of LCD and the extra keys on Logitech keyboards
WWW=		https://sourceforge.net/projects/g15tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
