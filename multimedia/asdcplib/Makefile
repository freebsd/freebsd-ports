# $FreeBSD$

PORTNAME=	asdcplib
PORTVERSION=	1.11.49
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.cinecert.com/asdcplib/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Open source implementation of SMPTE and the MXF Interop format

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-05-08

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expat=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}
INSTALL_TARGET=	install-strip
USES=		libtool ssl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
