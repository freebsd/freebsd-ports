# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.2.x/ \
		ftp://ftp.uk.xmms.org/xmms/1.2.x/ \
		ftp://ftp.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.ca.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.md.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.nl.xmms.org/xmms/1.2.x/ \
		ftp://ftp.de.xmms.org/xmms/1.2.x/

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	sobomax

MAINTAINER=	esk@ira.uka.de

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
		HAVE_MIKMOD=${HAVE_MIKMOD}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
HAVE_MIKMOD=	yes
PLIST_SUB+=	MIKMODPLUGIN:=""
.else
PLIST_SUB+=	MIKMODPLUGIN:="@comment "
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
PATCHFILES=	xmms-${PORTVERSION}-3dnow.patch.gz
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
.if !defined(WITHOUT_MIKMOD) || ( !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021 )
	@${ECHO_MSG}
.if !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_MIKMOD."
.endif
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable 3DNOW optimized decoding routines by defining WITHOUT_3DNOW."
.endif
	@${ECHO_MSG}
.endif

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^-pthread^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/aclocal|\$\(prefix\)/share/aclocal|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.post.mk>
