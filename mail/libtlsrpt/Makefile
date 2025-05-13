PORTNAME=	libtlsrpt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	mail

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Low-level C Library to implement TLSRPT into a MTA
WWW=		https://github.com/sys4/libtlsrpt

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sys4

.include <bsd.port.mk>
