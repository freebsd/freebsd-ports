# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.2.x/ 

MAINTAINER?=	esk@ira.uka.de

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

USE_X_PREFIX=	yes
USE_GTK=	yes
WANT_ESOUND=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libxmms/configure
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		HAVE_MIKMOD="${HAVE_MIKMOD}" \
		HAVE_VORBIS="${HAVE_VORBIS}"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
HAVE_MIKMOD=	yes
PLIST_SUB+=	MIKMODPLUGIN:=""
.else
PLIST_SUB+=	MIKMODPLUGIN:="@comment "
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.0:${PORTSDIR}/audio/libvorbis
HAVE_VORBIS=	yes
PLIST_SUB+=	VORBISPLUGIN:=""
.else
PLIST_SUB+=	VORBISPLUGIN:="@comment "
.endif

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS=	--without-gnome
.endif

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
PLIST_SUB+=	ESDPLUGIN:=""
.else
PLIST_SUB+=	ESDPLUGIN:="@comment "
.endif

.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=	--enable-3dnow
.endif

.if defined(WITHOUT_3DNOW) || ${OSVERSION} < 400021
post-extract:
	(cd ${WRKSRC}/Input/mpg123 && ${MV} decode_i586.s decode_i586.S && \
	  cd ${WRKSRC}/Visualization/blur_scope && ${MV} blur_8.s blur_8.S);
	${PERL} -pi.bak -e 's:\.s :\.S :g' ${WRKSRC}/Input/mpg123/Makefile.in
	${PERL} -pi.bak -e 's:blur_8.s:blur_8.S:g' \
	  ${WRKSRC}/Visualization/blur_scope/Makefile.in
.endif

pre-extract:
.if !defined(WITHOUT_MIKMOD) || !defined(WITHOUT_VORBIS) || ( !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021 )
	@${ECHO_MSG}
.if !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_MIKMOD."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable 3DNow! optimized decoding routines by defining WITHOUT_3DNOW."
.endif
	@${ECHO_MSG}
.endif

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/aclocal|\$\(prefix\)/share/aclocal|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	@${MKDIR} ${PREFIX}/share/xmms/Skins

.include <bsd.port.post.mk>
