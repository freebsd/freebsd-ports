# New ports collection makefile for:	misterproper
# Date created:				12 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	misterproper
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#ftp://misterproper.sourceforge.net/pub/misterproper/releases/ \
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME application designed to manage cyclic tasks

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix gnometarget
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
