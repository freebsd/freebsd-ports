# Ports collection makefile for:  authforce
# Date created:                   08.05.2002
# Whom:                           Andrey A. Chernov <ache@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	authforce
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	security www
MASTER_SITES=	http://kapheine.hypa.net/authforce/

MAINTAINER=	ache@FreeBSD.org
COMMENT=	HTTP authentication brute forcer

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl \
		intl.5:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lintl"

MAN1=		authforce.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
