# New ports collection makefile for:	stuphead
# Date created:		07 December 2000
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	stuphead
PORTVERSION=	0.4.9
CATEGORIES=	mail
MASTER_SITES=	http://stuphead.antex.ru/

MAINTAINER=	ozz@FreeBSD.org.ru

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's#DATADIRNAME=lib#DATADIRNAME=share#g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
