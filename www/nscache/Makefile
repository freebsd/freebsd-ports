# New ports collection makefile for:	nscache
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nscache
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netscape cache browser

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gtk12
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
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
		${PREFIX}/share/gnome/pixmaps

.include <bsd.port.mk>
