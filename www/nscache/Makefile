# New ports collection makefile for:	nscache
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nscache
PORTVERSION= 	0.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netscape cache browser

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--include-deps
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG}

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.include <bsd.port.post.mk>
