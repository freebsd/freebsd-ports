# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	0.7.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/www/mozilla:build
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		glade.4:${PORTSDIR}/devel/libglade
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		mozilla:${PORTSDIR}/www/mozilla

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
CFLAGS+=	-D_REENTRANT -D_THREAD_SAFE

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-mozilla-headers=${WRKDIRPREFIX}${.CURDIR}/../../www/mozilla/work/mozilla/dist/include \
		--with-mozilla-libs=${WRKDIRPREFIX}${.CURDIR}/../../www/mozilla/work/mozilla/dist/lib
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|-lpthread|-pthread|g'
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g ; \
			 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			 s|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/src/galeon

.include <bsd.port.mk>
