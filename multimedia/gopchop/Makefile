# ex:ts=8
# Ports collection makefile for:	GOPchop
# Date created:				Apr 24, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gopchop
PORTVERSION=	0.9.0
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://outflux.net/unix/software/GOPchop/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GOPchop-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG2 GOP-accurate editor

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2

SDLCONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GNOME=	gtk12
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDLCONFIG="${SDLCONFIG}"
CONFIGURE_ARGS=	--disable-mlib

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT 
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's| -mcpu=.*"|"|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|pixmaps/\$$(PACKAGE)|\$$(PACKAGE)/pixmaps|g ; \
		 s|-lglib||g'

.include <bsd.port.mk>
