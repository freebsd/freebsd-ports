# New ports collection makefile for:	ayttm
# Date created:			1 Mar 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ayttm
PORTVERSION=	0.4.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A "chat" program that combines AIM, ICQ, and Yahoo! Chat into one

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		ltdl.4:${PORTSDIR}/devel/libltdl \
		jasper.4:${PORTSDIR}/graphics/jasper \
		gpgme.9:${PORTSDIR}/security/gpgme \
		pspell.15:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_GCC=	3.2
USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gdkpixbuf gnometarget lthack
USE_OPENSSL=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# none
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-smtp --enable-jasper-filter

MAN1=		ayttm.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
CFLAGS+=        -O0  
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_LIBARTS)
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/libarts
PLIST_SUB+=	LIBARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUB+=	LIBARTS="@comment "
.endif

.if ${XFREE86_VERSION} >= 4 && !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft
CONFIGURE_ARGS+=	--enable-xft
CPPFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`
.endif

pre-everything::
	@${ECHO_MSG} "Ayttm has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_GNOME=esound	Truns off EsounD support"
	@${ECHO_MSG} "	WITH_LIBARTS=yes	Turns on libArts support"
	@${ECHO_MSG} "	WITHOUT_XFT=yes		Turns off Xft support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g; \
		 s|-pthread|${PTHREAD_CFLAGS:S/"//g}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
