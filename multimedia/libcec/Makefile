# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libcec
PORTVERSION=	2.1.4
CATEGORIES=	multimedia
MASTER_SITES=	GH

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Library to control Pulse-Eight's HDMI-CEC adapter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Pulse-Eight
GH_COMMIT=	81e3821
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}-repack

USES=		pathfix pkgconfig libtool
PATHFIX_MAKEFILEIN=Makefile.am
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} 's;-Wno-psabi;;' ${WRKSRC}/configure.ac

.include <bsd.port.options.mk>

.if ${ARCH} == armv6
CONFIGURE_ARGS=	--disable-rpi
.endif

.include <bsd.port.mk>
