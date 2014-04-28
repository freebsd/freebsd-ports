# $FreeBSD$

PORTNAME=	libijs
PORTVERSION=	0.35
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/ijs/download/
DISTNAME=	ijs-${PORTVERSION}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that supports plugin printer driver for Ghostscript

USES=		gmake libtool:keepla pkgconfig tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

.include <bsd.port.mk>
