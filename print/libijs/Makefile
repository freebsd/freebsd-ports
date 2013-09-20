# $FreeBSD$

PORTNAME=	libijs
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/ijs/download/
DISTNAME=	ijs-${PORTVERSION}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that supports plugin printer driver for Ghostscript

USES=		pkgconfig
USE_BZIP2=	yes
USE_GNOME=	lthack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

MAN1=		ijs-config.1

NO_STAGE=	yes
.include <bsd.port.mk>
