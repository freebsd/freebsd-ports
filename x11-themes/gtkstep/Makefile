# New ports collection makefile for:	gtkstep
# Version required:			1.5
# Date Created:				7 nov 98
# Whom:				 	Gilad Rom
#
# $Id: Makefile,v 1.5 1999/04/22 06:49:17 nectar Exp $
#

DISTNAME=	gtkstep-1.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www-info2.informatik.uni-wuerzburg.de/mitarbeiter/ulli/gtkstep/ \
		ftp://sunshine.informatik.uni-wuerzburg.de/pub/wmaker/gtkstep/

MAINTAINER=     rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
