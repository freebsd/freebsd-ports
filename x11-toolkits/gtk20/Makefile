# New ports collection makefile for:   gtk11-devel
# Version required:		1.1.16
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.44 1999/02/18 04:49:25 vanilla Exp $
#

DISTNAME=	gtk+-1.1.16
PKGNAME=	gtk-1.1.16
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	glib11d.2:${PORTSDIR}/devel/glib11-devel

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk11d
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtk-config.1

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${LOCALBASE}/share/aclocal
	@${INSTALL_DATA} ${WRKSRC}/gtk.m4 ${LOCALBASE}/share/aclocal/gtk11d.m4
	@if [ ! -f ${PREFIX}/share/info ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
