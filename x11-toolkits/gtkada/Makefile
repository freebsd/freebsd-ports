# New ports collection makefile for:   gtkada
# Date Created:			27 Nov 2000
# Whom:				Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gtkada
PORTVERSION=	2.4.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://libre2.adacore.com/GtkAda/ \
		http://libre.act-europe.fr/GtkAda/ \
		http://www.sourcefiles.org/Programming/Development/Interfaces/
DISTNAME=	GtkAda-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	Gtk2 binding for Ada

BUILD_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

CONFLICTS=	gtkada-devel-[0-9]* gtkada-gcc-[0-9]*
BROKEN=		does not build
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

USE_GL=		gl
USE_GNOME=	gtk20 libglade2
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL=GL

EXAMPLESDIR=	${DATADIR}/examples

.include <bsd.port.mk>
