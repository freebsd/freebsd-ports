# New ports collection makefile for:	scrollkeeper
# Date created:				6 April 2001
# Whom:					Rene Hexel <rh@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	scrollkeeper
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNOME:S,%SUBDIR%,stable/sources/scrollkeeper,}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

# Don't use USE_X_PREFIX - the port doesn't really require X11 to run.
# The reason why it should be in X11BASE is that GNOME is the primary
# (only?) consumer of this port, and BadThings[tm] happen if it's not
# put in the right place.
PREFIX?=        ${X11BASE}

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
