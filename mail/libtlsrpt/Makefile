PORTNAME=	libtlsrpt
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://github.com/sys4/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Low-level C Library to implement TLSRPT into a MTA
WWW=		https://github.com/sys4/libtlsrpt

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
