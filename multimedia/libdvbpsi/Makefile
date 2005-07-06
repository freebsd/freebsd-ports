# ex:ts=8
# Ports collection makefile for:	libdvbpsi
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvbpsi
PORTVERSION=	0.1.5
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdvbpsi/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	${PORTNAME}4-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A library for MPEG TS and DVB PSI tables decoding and generation

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-release
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall|$${CFLAGS}|g ; \
		 s|-O6||g' ${WRKSRC}/configure

.include <bsd.port.mk>
