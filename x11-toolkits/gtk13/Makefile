# New ports collection makefile for:   gtk12
# Version required:		1.2.2
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.48 1999/03/27 00:00:16 flathill Exp $
#

DISTNAME=	gtk+-1.2.2
PKGNAME=	gtk-1.2.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/gtk/v1.2/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	glib12.1:${PORTSDIR}/devel/glib12 \
		intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtk12-config.1

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${PREFIX}/share/themes/engines
	@if [ ! -f ${PREFIX}/share/info ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@${ECHO} '*********************************************************'
	@${ECHO} '*                                                       *'
	@${ECHO} '*     If you want to use autoconf with gtk,             *'
	@${ECHO} '*     Please copy gtk.m4 to /usr/local/share/aclocal    *'
	@${ECHO} '*     by yourself, thanks.                              *'
	@${ECHO} '*                                                       *'
	@${ECHO} '*********************************************************'

.include <bsd.port.mk>
