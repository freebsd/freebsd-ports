# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	0.7.6
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/sobomax/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		glade.4:${PORTSDIR}/devel/libglade
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}

.if !defined(WITH_FULL_MOZILLA)
MOZILLA=	mozilla-embedded
BUILD_DEPENDS+=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
MOZHEADERS=	${X11BASE}/include/${MOZILLA}
MOZLIBS=	${X11BASE}/lib/${MOZILLA}
.else
MOZILLA=	mozilla
BUILD_DEPENDS+=	/nonexistent:${PORTSDIR}/www/${MOZILLA}:build
MOZHEADERS=	${WRKDIRPREFIX}${.CURDIR}/../../www/mozilla/work/mozilla/dist/include
MOZLIBS=	${WRKDIRPREFIX}${.CURDIR}/../../www/mozilla/work/mozilla/dist/lib
.endif

USE_X_PREFIX=	yes
USE_NEWGCC=	yes
GNU_CONFIGURE=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
CFLAGS+=	-D_REENTRANT -D_THREAD_SAFE -fno-rtti

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-mozilla-includes="${MOZHEADERS}" \
		--with-mozilla-libs="${MOZLIBS}"
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITH_FULL_MOZILLA)
post-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} " By default the port uses mozilla-embedded for html rendering, but if you are"
	@${ECHO_MSG} " planning to use both Mozilla and Galeon you can instruct it to use mozilla by"
	@${ECHO_MSG} " defining \"WITH_FULL_MOZILLA\"."
	@${ECHO_MSG}
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|-lpthread|-pthread|g'

post-configure:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g ; \
			 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			 s|%%X11BASE%%|${X11BASE}|g ; \
			 s|%%MOZILLA%%|${MOZILLA}|g' ${WRKSRC}/src/galeon

.include <bsd.port.mk>
