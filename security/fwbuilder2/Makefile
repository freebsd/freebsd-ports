# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	0.8.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
USE_GNOMELIBS=	yes
WITHOUT_ESOUND=	yes
CONFIGURE_ARGS+=	--with-iconsdir=${X11BASE}/share/gnome/fwbuilder/pixmaps/ --with-templatedir=${X11BASE}/share/gnome/fwbuilder

post-extract:
	@${PERL} -pi -e "s/lc_r/pthread/" ${WRKSRC}/configure ;\
	${PERL} -pi -e "s|/usr/bin|${LOCALBASE}/bin|" ${WRKSRC}/etc/fwbuilder_prefs.xml.in
.for i in compiler-framework/Makefile.in gui/gnome-wrappers/Makefile.in \
	gui/Makefile.in ipchains/Makefile.in ipfilter/Makefile.in \
	iptables/Makefile.in
	@${PERL} -pi -e "s|^CFLAGS\s+=\s+-Wall\s+-g|CFLAGS = \@CFLAGS@ -Wall|" ${WRKSRC}/src/$i
.endfor

.include <bsd.port.mk>
