# $FreeBSD$

PORTNAME=	asdcplib
PORTVERSION=	1.11.49
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.cinecert.com/asdcplib/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Open source implementation of SMPTE and the MXF Interop format

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expat=${LOCALBASE}
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

.include <bsd.port.mk>
