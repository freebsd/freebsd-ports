# New ports collection makefile for:	nscache
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/nscache/Makefile,v 1.3 2007/08/07 03:35:07 mezz Exp $
#

PORTNAME=	nscache
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	SF \
		http://www.idata.sk/~ondrej/sw/

EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netscape cache browser

USE_GNOME=	gnomehier gtk12
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG} --disable-gnome
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/nscache.desktop \
		${PREFIX}/share/gnome/apps/Internet
	${INSTALL_DATA} ${WRKSRC}/nscache.xpm \
		${PREFIX}/share/pixmaps

.include <bsd.port.mk>
