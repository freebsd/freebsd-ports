# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	0.9
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/evolution

MAINTAINER=	sobomax@FreeBSD.org

# Note: gnomepilot support has been forcibly taken out for now, so
# we can save ourselves a little bit of build time

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml \
		glade.4:${PORTSDIR}/devel/libglade \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		gnomeprint.13:${PORTSDIR}/print/gnomeprint \
		oaf.0:${PORTSDIR}/devel/oaf \
		bonobo.2:${PORTSDIR}/devel/bonobo \
		gnomevfs.0:${PORTSDIR}/devel/gnomevfs \
		unicode.0:${PORTSDIR}/devel/libunicode \
		gtkhtml.8:${PORTSDIR}/www/gtkhtml \
		ldap.1:${PORTSDIR}/net/openldap # \
#		gpilotd.0:${PORTSDIR}/palm/gnomepilot

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libical/configure
CONFIGURE_ARGS=	# --with-pisock=${LOCALBASE}/pilot --enable-pilot-conduits=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
