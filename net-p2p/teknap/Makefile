# New ports collection makefile for:	TekNap napster client
# Date created:				6 Jul 2000
# Whom:					Carl Johan Madestrand
#
# $FreeBSD$
#

PORTNAME=	TekNap
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ukug.uk.freebsd.org/pub/lord_cj/	

MAINTAINER=	LoRd_CJ@dalusers.com

.if defined(WITH_MP3)
BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
.endif
.if defined(WITH_XMMS)
BUILD_DEPENDS=	xmms:${PORTSDIR}/audio/xmms
.endif

WRKSRC=		${WRKDIR}/TekNap

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

USE_GMAKE=	yes
WANT_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
CONFIGURE_ARGS+=--with-gtk
.else
CONFIGURE_ARGS+=--without-gtk
.endif

.if defined(WITH_MP3)
CONFIGURE_ARGS+=--enable-mp3
.endif

.if defined(WITH_XMMS)
CONFIGURE_ARGS+=--enable-xmms
.endif

pre-extract:
	@${ECHO} "Available switches:"
	@${ECHO} "-------------------"
	@${ECHO} "WITH_MP3 - Support MP3 playback"
	@${ECHO} "WITH_XMMS - Support XMMS"

pre-configure:
	@${PERL} -pi -e "s:-lc_r:${PTHREAD_LIBS}:g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/TekNap
	${TAR} --directory ${WRKSRC}/teknap-help -cf - . --exclude CVS | \
	${TAR} --directory ${PREFIX}/share/TekNap/help -xf -
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/TekNap
	@${ECHO}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO}
.endif

.include <bsd.port.post.mk>
