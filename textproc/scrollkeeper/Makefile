# New ports collection makefile for:	scrollkeeper
# Date created:				6 April 2001
# Whom:					Rene Hexel <rh@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	scrollkeeper
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNOME:S,%SUBDIR%,stable/sources/scrollkeeper,}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

# It has to go in X_PREFIX to work with the rest of GNOME, for which
# scrollkeeper was primarily designed in the first place.  It's an
# exceptionally deep dependency (gnomelibs needs it), so to put it
# in the right place, we have to do this kludge
USE_X_PREFIX=	yes

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=/var --datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN8=		scrollkeeper-config.8 scrollkeeper-preinstall.8 \
		scrollkeeper-rebuilddb.8 scrollkeeper-update.8

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e   \
		's|\$$\(LN_S\) -f -n|\$$\(LN_S\) -f|g'

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/scrollkeeper/TOC

.include <bsd.port.mk>
