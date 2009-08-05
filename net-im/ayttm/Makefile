# New ports collection makefile for:	ayttm
# Date created:			1 Mar 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ayttm
PORTVERSION=	0.5.0.111
CATEGORIES=	net-im
.for mirror in nchc kent ufpr heanet switch puzzle osdn ovh
MASTER_SITES+=http://${mirror}.dl.sourceforge.net/project/ayttm/ayttm/${PORTVERSION:R}-${PORTVERSION:E}/
.endfor
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	unixmania@gmail.com
COMMENT=	A "chat" program that combines AIM, ICQ, and Yahoo! Chat into one

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		jasper.4:${PORTSDIR}/graphics/jasper \
		gpgme.18:${PORTSDIR}/security/gpgme \
		pspell.16:${PORTSDIR}/textproc/aspell

OPTIONS=	ARTS	"Enable aRts support"		off \
		ESOUND	"Enable EsounD support"		off \
		AIM_TOC	"Include aim-toc service"	off \
		ICQ_TOC "Include icq-toc service"	off

USE_BZIP2=	yes
USE_XORG=	xpm xscrnsaver
USE_GNOME=	gnometarget gtk20
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl:22 libtool:22
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

.if defined(WITH_AIM_TOC)
CONFIGURE_ARGS+=	--enable-aim-toc
PLIST_SUB+=		AIM_TOC=""
.else
PLIST_SUB+=		AIM_TOC="@comment "
.endif

.if defined(WITH_ICQ_TOC)
CONFIGURE_ARGS+=	--enable-icq-toc
PLIST_SUB+=		ICQ_TOC=""
.else
PLIST_SUB+=		ICQ_TOC="@comment "
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
