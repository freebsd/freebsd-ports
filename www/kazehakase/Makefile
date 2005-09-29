# New ports collection makefile for:	kazehakase
# Date created:		2004-04-06
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	kazehakase
PORTVERSION=	0.3.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/16705

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Kazehakase is a browser with gecko engine like Epiphany or Galeon

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/${MOZILLA}-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/${MOZILLA}${HEADERS_SUFX}
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/${MOZILLA}-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/${MOZILLA}${HEADERS_SUFX}

USE_LIBTOOL_VER=15
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-gecko-engine=${MOZILLA:S/-devel//} \
		--disable-ssl

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		kazehakase.1

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1

.if defined(WITH_MIGEMO)
USE_RUBY=	yes
USE_PERL=	yes
BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
.endif

.include <bsd.port.pre.mk>

WITH_MOZILLA?=	firefox

# !!! gtk-webcore higly experimental right now and not very stable !!!
# See https://mail.gna.org/public/kazehakase-devel/2004-10/msg00001.html
# on how to use gtk-webcore with kazehakase. and yes you still have to
# have mozilla even if you don't use it in kazehakase.
.if defined(WITH_GTKWEBCORE)
LIB_DEPENDS+=	nrcit.0:${PORTSDIR}/www/osb-nrcit
CONFIGURE_ARGS+=--enable-gtk-webcore
.endif

.if defined(WITH_THUMBNAIL) || exists(${LOCALBASE}/bin/gs)
USE_GHOSTSCRIPT=yes
.endif

.if !defined(WITH_MOZILLA)
MOZILLA=	firefox
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla"
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel"
MOZILLA=	mozilla
HEADERS_SUFX=
#HEADERS_SUFX=	-devel
.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif
.else
MOZILLA=	firefox
HEADERS_SUFX=
.endif
.endif
.endif

.if exists(${LOCALBASE}/bin/estxview)
WITH_ESTRAIER=	yes
.endif

.if defined(WITH_MIGEMO)
.if ${ARCH} == "i386" || ${ARCH} == "sparc64"
RUN_DEPENDS+=	migemo:${PORTSDIR}/japanese/migemo

CONFIGURE_ARGS+=	--enable-migemo
.endif
.endif

.if !defined(WITHOUT_ESTRAIER)
RUN_DEPENDS+=	estxview:${PORTSDIR}/textproc/estraier
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Enable Migemo (Japanese incremental search) by defining WITH_MIGEMO"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Enable Thumbnail support by defining WITH_THUMBNAIL"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Disable Estraier, A full-text search engine for searching your history"
	@${ECHO_MSG} " by defining WITHOUT_ESTRAIER"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default ${PORTNAME} uses www/firefox for Gecko support, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " firefox "
	@${ECHO_MSG} " mozilla "
#	@${ECHO_MSG} " mozilla-devel "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Currently you are using ${WITH_MOZILLA}"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g; \
		s|%%MOZILLA%%|${MOZILLA}|; s|%%HEADERS_SUFX%%|${HEADERS_SUFX}|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/migemo|${LOCALBASE}/share/migemo|; \
		s|=beginner|=medium|' ${WRKSRC}/etc/kzrc
.if defined(WITH_MIGEMO)
	@${REINPLACE_CMD} -e 's|migemo=fals|migemo=tru|' ${WRKSRC}/etc/kzrc
.endif
.if defined(WITH_THUMBNAIL)
	@${ECHO_MSG} "create_thumbnail=true" >> ${WRKSRC}/etc/kzrc
.endif

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%FLASHPLAYER%%|${FLASHPLAYER}|g' < ${FILESDIR}/kazehakase \
		> ${WRKDIR}/kazehakase

post-install:
	@${MV} -f ${PREFIX}/bin/kazehakase ${PREFIX}/bin/kazehakase-bin
	${INSTALL_SCRIPT} ${WRKDIR}/kazehakase ${PREFIX}/bin

.include <bsd.port.post.mk>
