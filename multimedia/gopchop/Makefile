# ex:ts=8
# Ports collection makefile for:	GOPchop
# Date created:				Apr 24, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gopchop
PORTVERSION=	0.8
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://outflux.net/unix/software/GOPchop/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GOPchop-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG2 GOP-accurate editor

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \
		SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		intl.4:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_GNOME=	gtk12
USE_REINPLACE=	yes
SDLCONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -DHAVE_DECL_GETOPT -I${LOCALBASE}/include" \
	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt" \
	SDLCONFIG="${SDLCONFIG}"

post-patch:
	@${REINPLACE_CMD} -e 's|-lglib||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
