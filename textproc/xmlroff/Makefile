# New ports collection makefile for:	xmlroff
# Date created:		1 January 2005
# Whom:			James Earl
#
# $FreeBSD$
#

PORTNAME=	xmlroff
PORTVERSION=	0.3.3
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL formatter that produces PDF and PostScript

LIB_DEPENDS=	pangoxsl-1.0.600:${PORTSDIR}/x11-toolkits/pangoxsl

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget libgnomeprint libxslt
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
