# New ports collection makefile for:	TekNap napster client
# Date created:				6 Jul 2000
# Whom:					Carl Johan Madestrand
#
# $FreeBSD$
#

PORTNAME=	TekNap
PORTVERSION=	1.3.g
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://got.net/~brian/teknap/ \
		ftp://ftp.arnes.si/packages2/OpenBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.g/g/}

MAINTAINER=	calle.madestrand@norrgarden.se
COMMENT=	Console napster client

.if defined(WITH_MP3)
BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
.endif
.if defined(WITH_XMMS)
BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
.endif

WRKSRC=		${WRKDIR}/TekNap
USE_REINPLACE=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=--with-gtk
PKGNAMESUFFIX=	-gtk
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
	@${REINPLACE_CMD} -e "s:-lc_r:${PTHREAD_LIBS}:g" ${WRKSRC}/configure

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
