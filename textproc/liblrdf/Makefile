# New ports collection Makefile for:	liblrdf
# Date created:			26 April 2003
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	liblrdf
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://plugin.org.uk/releases/lrdf/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	raptor.2:${PORTSDIR}/textproc/raptor

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

post-patch:
	${REINPLACE_CMD} -e 's,1:2:2,1:2:1,' ${WRKSRC}/configure

.include <bsd.port.mk>
