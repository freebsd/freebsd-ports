# New ports collection makefile for:	faces-1.6.1
# Date created:		09 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
#			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	faces
PORTVERSION=	1.7.7
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=    intl.1:${PORTSDIR}/devel/gettext

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} --enable-imap --enable-pop \
		--enable-name-unknown --with-spooldir=/var/mail \
		--with-facedir=${PREFIX}/share/faces

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=     APPDEF="@comment "
.else # with X11
PLIST_SUB+=     APPDEF=""
USE_GTK=yes
# NAS is only possible with X11
.if !defined(WITHOUT_AUDIO)
.if defined(USE_NAS)
CONFIGURE_ARGS+=--enable-audio --with-audio-cmd=${X11BASE}/bin/auplay
RUN_DEPENDS=	auplay:${PORTSDIR}/audio/nas
PLAY_COMMAND=	auplay
.endif # USE_NAS
.endif # WITHOUT_AUDIO
.endif # WITHOUT_X11

.if !defined(WITHOUT_AUDIO)
.if defined(USE_SOX)
CONFIGURE_ARGS+=--enable-audio --with-audio-cmd=${LOCALBASE}/bin/play
RUN_DEPENDS=	play:${PORTSDIR}/audio/sox
PLAY_COMMAND=	play
.else
CONFIGURE_ARGS+=--enable-audio --with-audio-cmd=${LOCALBASE}/bin/rplay
RUN_DEPENDS=	rplay:${PORTSDIR}/audio/rplay
PLAY_COMMAND=	rplay
.endif # USE_SOX
.endif # WITHOUT_AUDIO

CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include -I../compface" \
		CFLAGS="-I${LOCALBASE}/include -I../compface" \
		LIBS="-L${LOCALBASE}/lib -L../compface"

.if defined(USE_GTK)
CONFIGURE_ENV+= GTK_CONFIG="${X11BASE}/bin/gtk12-config"
.endif

INSTALLS_SHLIB=	yes
MAN1=		compface.1 faces.1
MAN3=		compface.3
MLINKS=		compface.1 uncompface.1 \
		compface.3 uncompface.3

pre-everything:
	@${ECHO_MSG} "***"
	@${ECHO_MSG} "*** Note: You can use the following options:"
	@${ECHO_MSG} "***       -DWITHOUT_AUDIO build without audio support!"
	@${ECHO_MSG} "***       -DWITHOUT_X11   build without X11/GTK support!"
	@${ECHO_MSG} "***       -DWITH_NAS      build with NAS audio support. Needs X11!"
	@${ECHO_MSG} "***       -DWITH_SOX      build with SOX audio support!"
	@${ECHO_MSG} "*** The default is X11/GTK with rplay audio support!"
	@${ECHO_MSG} "***"

# I have no better idea up to now
# Insall the working Makefile for compface from the old faces port
# This was much less complex an builds the shared libs, too
post-configure:
	${CP} ${FILESDIR}/Makefile.compface ${WRKSRC}/compface/Makefile
	${CP} -pf ${WRKSRC}/faces/faces.man ${WRKSRC}/faces/faces.man.orig
	${SED} -e "s%/usr/local/faces%${PREFIX}/share/faces%" \
	       -e "s%/var/spool/mail%/var/mail%" < ${WRKSRC}/faces/faces.man.orig > ${WRKSRC}/faces/faces.man
	${CP} -pf ${WRKSRC}/faces/Faces.ad ${WRKSRC}/faces/Faces.ad.orig
.if !defined(WITHOUT_AUDIO)
.if defined(USE_NAS)
	${SED} -e "s%rplay%auplay%" < ${WRKSRC}/faces/Faces.ad.orig > ${WRKSRC}/faces/Faces.ad
.endif
.if defined(USE_SOX)
	${SED} -e "s%rplay%play%" < ${WRKSRC}/faces/Faces.ad.orig > ${WRKSRC}/faces/Faces.ad
.endif
# For rplay we have nothing to do!
.else # WITHOUT_AUDIO
	${SED} -e "s%^faces.audioSupport.*%faces.audioSupport:		false%" < ${WRKSRC}/faces/Faces.ad.orig > ${WRKSRC}/faces/Faces.ad
.endif # WITHOUT_AUDIO

post-install:
.if !defined(WITHOUT_X11)
	${CP} -f ${WRKSRC}/faces/Faces.ad ${PREFIX}/lib/X11/app-defaults/Faces
.endif
.if !defined(NOPORTDOCS)
	if [ ! -e ${PREFIX}/share/doc/${PORTNAME} ]; then \
		${MKDIR} ${PREFIX}/share/doc/${PORTNAME}; \
	       	${CP} -f ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}; \
	fi
.endif
	${INSTALL_SCRIPT} ${FILESDIR}/ikon2xbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/xbm2ikon ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/xbmcut48 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/xbmsize48 ${PREFIX}/bin

.include <bsd.port.mk>
