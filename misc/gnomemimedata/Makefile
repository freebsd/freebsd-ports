# New ports collection makefile for:	gnomemimedata
# Date created:				22 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomemimedata
PORTVERSION=	2.4.1
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-mime-data/2.4
DISTNAME=	gnome-mime-data-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MIME and Application database for GNOME

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomehier gnomeprefix gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.mk>
