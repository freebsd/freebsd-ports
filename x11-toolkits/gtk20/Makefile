# New ports collection makefile for:   gtk11-devel
# Version required:		1.1.12
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.40 1999/01/04 08:43:06 vanilla Exp $
#

DISTNAME=	gtk+-1.1.12
PKGNAME=	gtk-1.1.12
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	glib11d.2:${PORTSDIR}/devel/glib11-devel

USE_X_PREFIX=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
USE_PERL5=	yes
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL='$${INSTALL} -c' \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk11d

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
