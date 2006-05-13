# New ports collection makefile for:	xvidcap
# Date created:		Sat 24 April 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		xvidcap
PORTVERSION=		1.1.3.7
PORTREVISION=		3
CATEGORIES=		sysutils multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION:C/.7/-p7/}

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Capture your X display to individual frames or MPEG video

#LIB_DEPENDS=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg	# To be reactivated after 1.1.4
#LIB_DEPENDS=		mp3lame.0:${PORTSDIR}/audio/lame
RUN_DEPENDS=		animate:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
#CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
#			LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib	\
			--with-forced-embedded-ffmpeg	# To be removed after 1.1.4pre2?
USE_GETOPT_LONG=	yes

PLIST_FILES=		bin/xvidcap

PORTDOCS=		AUTHORS ChangeLog INSTALL NEWS README TODO XVidcap.ad
DOC_HOOK=		$$(MAKE) $$(AM_MAKEFLAGS) install-data-hook

MAN1=			xvidcap.1

.if !defined(WITHOUT_GTK)
USE_GNOME=		gtk20
CONFIGURE_ARGS+=	--with-gtk2
PLIST_SUB+=		GTK=""
PLIST_FILES+=		bin/gvidcap
MAN1+=			gvidcap.1
.else
PLIST_SUB+=		GTK="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|'	\
		 -e 's|@PTHREAD_CFLAGS@|${PTHREAD_CFLAGS}|'		\
			${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|${DOC_HOOK}|#${DOC_HOOK}|'		\
			${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
