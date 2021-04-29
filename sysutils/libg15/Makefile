PORTNAME=	libg15
DISTVERSION=	3.0.3
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/menelkir/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	menelkir@itroll.org
COMMENT=	API for control of LCD and the extra keys on Logitech keyboards

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:gcc-c++11-lib gmake libtool tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
