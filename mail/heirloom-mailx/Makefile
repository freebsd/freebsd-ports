# New ports collection makefile for:	nail
# Date created:		20 October 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nail
PORTVERSION=	10.7
CATEGORIES=	mail
MASTER_SITES=	http://nail.berlios.de/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD mail utility with MIME extensions

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl --with-rcfile="${PREFIX}/etc/nail.rc"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-liconv"
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		nail.1

.include <bsd.port.mk>
