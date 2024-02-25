PORTNAME=	libijs
PORTVERSION=	0.35
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/ijs/download/
DISTNAME=	ijs-${PORTVERSION}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that supports plugin printer driver for Ghostscript
WWW=		https://www.linuxprinting.org/ijs/

LICENSE=	MIT

USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
