# New ports collection makefile for:   gtk
# Version required:		1.1.2
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.31 1998/12/10 13:18:16 vanilla Exp $
#

DISTNAME=	gtk+-1.1.2
PKGNAME=	gtk-1.1.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	glib11.0:${PORTSDIR}/devel/glib

BROKEN=		upgrade

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk11

MAN1=		gtk-config.1

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
