# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	1.0.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/mozilla/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA} \
		msgfmt-new:${PORTSDIR}/devel/gettext-devel
LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}

#BROKEN=		"b0rken with Mozilla-0.9.1"

#WITH_FULL_MOZILLA=	"Problems with missed scrollbars when linked with mozilla-embedded"

.if !defined(WITH_FULL_MOZILLA)
MOZILLA=	mozilla-embedded
.else
MOZILLA=	mozilla
.endif

USE_X_PREFIX=	yes
USE_NEWGCC=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -D_REENTRANT ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		MSGFMT=${LOCALBASE}/bin/msgfmt-new \
		XGETTEXT=${LOCALBASE}/bin/xgettext-new
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		galeon.1

post-extract:
.if !defined(WITH_FULL_MOZILLA)
	@${ECHO_MSG}
	@${ECHO_MSG} " By default the port uses mozilla-embedded for html rendering, but if you are"
	@${ECHO_MSG} " planning to use both Mozilla and Galeon you can instruct it to use mozilla by"
	@${ECHO_MSG} " defining \"WITH_FULL_MOZILLA\"."
	@${ECHO_MSG}
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|-liconv|-lgiconv|g ; s|iconv\.h|giconv.h|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'
	@find ${WRKSRC} -name "*.[ch]" | xargs ${PERL} -pi -e \
		's|iconv\.h|giconv.h|g'

post-configure:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g ; \
			 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			 s|%%X11BASE%%|${X11BASE}|g ; \
			 s|%%MOZILLA%%|${MOZILLA}|g' ${WRKSRC}/src/galeon

pre-install:
	@-${X11BASE}/bin/gconftool --shutdown

.include <bsd.port.mk>
