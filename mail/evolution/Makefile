# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/evolution

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtkhtml.10:${PORTSDIR}/www/gtkhtml \
		ldap.1:${PORTSDIR}/net/openldap

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
