# New ports collection makefile for:    libdvdnav
# Date created:         21 May 2002
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	libdvdnav
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dvd

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	The library for the xine-dvdnav plugin

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name=''
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib|-L${LOCALBASE}/lib|g ; \
		 s|-I/usr/local/include|-I${LOCALBASE}/include|g ; \
		 s|aclocal-1.7|${TRUE}|g ; \
		 s|automake-1.7|${TRUE}|g ; \
		 s|autoconf|${TRUE}|g ; \
		 s|autoheader|${TRUE}|g' ${WRKSRC}/configure \
		 ${WRKSRC}/missing ${WRKSRC}/aclocal.m4 ${WRKSRC}/autogen.sh

.include <bsd.port.mk>
