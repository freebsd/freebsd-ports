# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	0.10.4
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL:S/%SUBDIR%/sobomax/}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/mozilla/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		gnomevfs.0:${PORTSDIR}/devel/gnomevfs \
		oaf.0:${PORTSDIR}/devel/oaf
		
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}

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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			  -D_REENTRANT ${PTHREAD_CFLAGS} -fno-rtti" \
		LIBS="-L${LOCALBASE}/lib -L${WRKSRC} ${PTHREAD_LIBS} ${GCC_R_LIB}"

.if exists(/usr/lib/libgcc_r.a)
GCC_R_LIB=	-lgcc_r
.endif

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
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

post-configure:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g ; \
			 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			 s|%%X11BASE%%|${X11BASE}|g ; \
			 s|%%MOZILLA%%|${MOZILLA}|g' ${WRKSRC}/src/galeon

.include <bsd.port.mk>
