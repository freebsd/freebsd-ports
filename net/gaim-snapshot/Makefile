# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		gaim
PORTVERSION=		0.51
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
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=			gaim.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=		yes
RUN_DEPENDS=		ispell:${PORTSDIR}/textproc/ispell
CONFIGURE_ARGS+=	--enable-panel
.else
CONFIGURE_ARGS+=	--disable-gnome
BUILD_DEPENDS=		${X11BASE}/bin/gdk-pixbuf-config:${PORTSDIR}/graphics/gdk-pixbuf
.endif
.if defined(HAVE_ESOUND)
USE_ESOUND=		yes
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

pre-patch:
	@${PERL} -pi.orig -e 's|-lpthreads|${PTHREAD_LIBS:S/"//g}|g; \
		s|-lpthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

.include <bsd.port.post.mk>
