# New ports collection makefile for:   gtk11-devel
# Version required:		1.1.7
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.34 1998/12/22 07:56:14 asami Exp $
#

DISTNAME=	gtk+-1.1.7
PKGNAME=	gtk-1.1.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	glib11d.1:${PORTSDIR}/devel/glib11-devel

USE_X_PREFIX=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
BROKEN=		requires perl5
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL='$${INSTALL} -c' \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk11d

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
