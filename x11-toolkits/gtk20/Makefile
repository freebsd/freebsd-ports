# New ports collection makefile for:   gtk
# Version required:		1.1.1
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.23 1998/08/12 10:38:28 vanilla Exp $
#

DISTNAME=	gtk+-1.1.1
PKGNAME=	gtk-1.1.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/pub/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	glib11\\.0\\.:${PORTSDIR}/devel/glib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk11

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
