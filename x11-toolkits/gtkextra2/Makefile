# New ports collection makefile for:	gtkextra
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkextra
PORTVERSION=	0.99.17
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://gtkextra.sourceforge.net/src/ \
		${MASTER_SITE_SOURCEFORGE} \
		http://magnet.fsu.edu/~feiguin/gtk/src/
MASTER_SITE_SUBDIR=	scigraphica
DISTNAME=	${PORTNAME:S/gtk/gtk+/}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
