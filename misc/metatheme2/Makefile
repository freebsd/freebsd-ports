# New ports collection makefile for:    metatheme2
# Date created:                         19 May 2002
# Whom:                                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metatheme2
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/0.9
DISTNAME=	metatheme-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An utility for managing "theme sets" that accomodate gtk, window manager, etc

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgnomeui
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	VERSION=${PORTVERSION}

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		 s|[(]datadir[)]/locale|(prefix)/share/locale|g'

post-configure:
	@${FIND} ${WRKSRC}/plugins -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%X11BASE%%|${X11BASE}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g'

.include <bsd.port.mk>
