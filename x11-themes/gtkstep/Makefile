# New ports collection makefile for:   gtkstep
# Version required:		1.0.6
# Date Created:			7 nov 98
# Whom:			 	Gilad Rom
#
# $Id: Makefile,v 1.1.1.1 1998/11/08 17:00:25 eivind Exp $
#

DISTNAME=	gtk+-1.0.6
PKGNAME=	gtkstep-1.0.6
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.0/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.0/ \
		http://www.ameth.org/gimp/gtk/v1.0/

PATCH_SITES=	http://www-info2.informatik.uni-wuerzburg.de/mitarbeiter/ulli/gtkstep/source/
PATCHFILES=	gtkstep-1.0.6-2.patch.gz

MAINTAINER=     rom_glsa@ein-hashofet.co.il

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk10

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
