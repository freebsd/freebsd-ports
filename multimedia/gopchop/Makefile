# ex:ts=8
# Ports collection makefile for:	GOPchop
# Date created:				Apr 24, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gopchop
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://outflux.net/unix/software/GOPchop/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GOPchop-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libvo.a:${PORTSDIR}/multimedia/libmpeg2
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include -D__GNU_LIBRARY__ ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lgnugetopt ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL |-lSDL-1.1 |g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lglib||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
