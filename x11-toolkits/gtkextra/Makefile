# New ports collection makefile for:	gtkextra
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkextra
PORTVERSION=	0.99.17
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://gtkextra.sourceforge.net/src/ \
		SF/scigraphica/scigraphica-0.x/0.8.0-source		

DISTNAME=	${PORTNAME:S/gtk/gtk+/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A useful widget set complementary to GTK+

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

.include <bsd.port.mk>
