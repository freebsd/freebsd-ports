# Ports collection makefile for:  authforce
# Date created:                   08.05.2002
# Whom:                           Andrey A. Chernov <ache@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       authforce
PORTVERSION=    0.9.6
CATEGORIES=     security www
MASTER_SITES=   http://kapheine.hypa.net/authforce/

MAINTAINER=     ache@FreeBSD.org

LIB_DEPENDS=    gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		curl.2:${PORTSDIR}/ftp/curl \
		intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=      yes

GNU_CONFIGURE=  yes
CONFIGURE_ENV+= CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lgnugetopt -lintl"

MAN1=           authforce.1
MANCOMPRESSED=  yes

.include <bsd.port.mk>
