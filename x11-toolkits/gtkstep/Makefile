# New ports collection makefile for:	gtkstep
# Version required:			1.4
# Date Created:				7 nov 98
# Whom:				 	Gilad Rom
#
# $Id: Makefile,v 1.2 1998/12/10 13:18:16 vanilla Exp $
#

DISTNAME=	gtkstep-1.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www-info2.informatik.uni-wuerzburg.de/mitarbeiter/ulli/gtkstep/ \
		ftp://sunshine.informatik.uni-wuerzburg.de/pub/wmaker/gtkstep/

MAINTAINER=     rom_glsa@ein-hashofet.co.il

LIB_DEPENDS=	gdk_imlib.2:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11d-config"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
