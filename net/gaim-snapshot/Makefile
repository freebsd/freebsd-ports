# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		gaim
PORTVERSION=		0.11.0pre10
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.marko.net/pub/gaim/ \
			${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jim@FreeBSD.org

USE_BZIP2=		yes
USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GTK=		yes
WANT_ESOUND=		yes
WANT_GNOME=		yes
USE_LIBTOOL=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"

MAN1=			gaim.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=		yes
RUN_DEPENDS=		ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=	--enable-panel
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif
.if defined(HAVE_ESOUND)
USE_ESOUND=		yes
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

.include <bsd.port.post.mk>
