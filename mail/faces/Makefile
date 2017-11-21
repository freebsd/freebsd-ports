# Created by: Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
# $FreeBSD$

PORTNAME=	faces
PORTVERSION=	1.7.7
PORTREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Visual mail, user, and print face server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	X11 DOCS NLS AUDIO
OPTIONS_DEFAULT=	X11
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	NAS RPLAY SOX
AUDIO_DESC=	Audio support
X11_DESC=	X11/GTK support
RPLAY_DESC=	rplay audio support
SOX_DESC=	Sox audio support

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

OPTIONS_SUB=	yes

X11_USE=	GNOME=gtk12
X11_CPPFLAGS=	-I../compface -I${LOCALBASE}/include
X11_LDFLAGS=	-L../compface -L${LOCALBASE}/lib
X11_CONFIGURE_ON=	--enable-imap --enable-pop \
		--enable-name-unknown --with-spooldir=/var/mail \
		--with-facedir=${DATADIR}
X11_CONFIGURE_WITH=	x

AUDIO_CONFIGURE_ENABLE=	audio

NAS_CONFIGURE_ON=	--with-audio-cmd=${LOCALBASE}/bin/auplay
NAS_RUN_DEPENDS=	auplay:audio/nas

SOX_CONFIGURE_ON=	--with-audio-cmd=${LOCALBASE}/bin/play
SOX_RUN_DEPENDS=	play:audio/sox

RPLAY_CONFIGURE_ON=	--with-audio-cmd=${LOCALBASE}/bin/rplay
RPLAY_RUN_DEPENDS=	rplay:audio/rplay

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README

.include <bsd.port.options.mk>

# I have no better idea up to now
# Install the working Makefile for compface from the old faces port
# This was much less complex an builds the shared libs, too
post-patch:
	@${REINPLACE_CMD} -e "s%/usr/local/faces%${DATADIR}%g ; \
		 s%/var/spool/mail%/var/mail%g" ${WRKSRC}/faces/faces.man
	@${LN} -sf ${WRKSRC}/faces/faces.man ${WRKSRC}/faces/faces.1
.if ${PORT_OPTIONS:MNAS}
	@${REINPLACE_CMD} -e "s%rplay%auplay%" ${WRKSRC}/faces/Faces.ad
.elif ${PORT_OPTIONS:MSOX}
	@${REINPLACE_CMD} -e "s%rplay%play%" ${WRKSRC}/faces/Faces.ad
.elif ${PORT_OPTIONS:MRPLAY}
	# nada
.else
	@${REINPLACE_CMD} -e "s%^faces.audioSupport.*%faces.audioSupport:		false%" ${WRKSRC}/faces/Faces.ad
.endif

do-build:
	cd ${WRKSRC}/compface && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${FILESDIR}/Makefile.compface ${MAKE_ARGS} ${ALL_TARGET}
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC}/faces && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compface/compface ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/compface/uncompface ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/compface/compface.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/compface/libcompface.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/compface/libcompface.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libcompface.so.1 ${STAGEDIR}${PREFIX}/lib/libcompface.so
	${INSTALL_MAN} ${WRKSRC}/compface/compface.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/compface/compface.3 ${STAGEDIR}${MANPREFIX}/man/man3
	${INSTALL_SCRIPT} ${FILESDIR}/ikon2xbm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/xbm2ikon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/xbmcut48 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/xbmsize48 ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/faces/faces ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/faces/faces.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/faces/Faces.ad ${STAGEDIR}${LOCALBASE}/lib/X11/app-defaults/Faces
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
