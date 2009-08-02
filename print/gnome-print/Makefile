# New ports collection makefile for:	gnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/print/gnome-print/Makefile,v 1.6 2007/09/24 19:40:45 mezz Exp $
#

PORTNAME=	gnome-print
PORTVERSION=	0.37
PORTREVISION=	8
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DISTNAME=	gnome-print-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_GHOSTSCRIPT_RUN=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gnomelibs gnomecanvas
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${TOUCH} ${PREFIX}/etc/gnome/fonts/gnome-print-x11.fontmap

.include <bsd.port.mk>
