# New ports collection makefile for:	ayttm
# Date created:			1 Mar 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ayttm
PORTVERSION=	0.5.0.45
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	unixmania@gmail.com
COMMENT=	A "chat" program that combines AIM, ICQ, and Yahoo! Chat into one

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		jasper.4:${PORTSDIR}/graphics/jasper \
		gpgme.17:${PORTSDIR}/security/gpgme \
		pspell.16:${PORTSDIR}/textproc/aspell

OPTIONS=	ARTS   "Enable aRts support"   off \
		ESOUND "Enable EsounD support" off

USE_BZIP2=	yes
USE_XORG=	xpm xscrnsaver
USE_GNOME=	gnometarget gtk20
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl:15 libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-oscar --disable-workwizu --enable-smtp --enable-lj

MAN1=		ayttm.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc:${PORTSDIR}/audio/arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-L/usr/local/lib||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 /CFLAGS=/s|-pthread|${PTHREAD_CFLAGS}|g ; \
		 s|-DGTK_DISABLE_DEPRECATED||g ; \
		 /LIBS=/s|-L/usr/X11R6/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/gnome/apps/Internet|/applications|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-L/usr/local/lib/pth/||g ; \
		 s|-lproxy|../libproxy/libproxy.a|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
