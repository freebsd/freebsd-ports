# ex:ts=8
# Ports collection makefile for:	libdvbpsi
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvbpsi
PORTVERSION=	0.1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/libdvbpsi/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for MPEG TS and DVB PSI tables decoding and generation

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-release
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall|$${CFLAGS}|g ; \
		 s|-O6||g' ${WRKSRC}/configure

.include <bsd.port.mk>
