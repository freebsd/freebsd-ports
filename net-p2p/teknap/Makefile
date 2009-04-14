# New ports collection makefile for:	TekNap napster client
# Date created:				6 Jul 2000
# Whom:					Carl Johan Madestrand
#
# $FreeBSD$
#

PORTNAME=	TekNap
PORTVERSION=	1.3.g
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://got.net/~brian/teknap/ \
		ftp://ftp.arnes.si/packages2/OpenBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.g/g/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console napster client

.if defined(WITH_MP3)
BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
.endif
.if defined(WITH_XMMS)
BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
.endif

WRKSRC=		${WRKDIR}/TekNap

PLIST_FILES=	bin/TekNap \
		bin/TekNap-1.3g

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
DOCSDIR=	${PREFIX}/share/doc/TekNap
PORTDOCS=	*
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

post-patch:
	@${REINPLACE_CMD} -e '/mkinstalldirs/ s,$$(HELPDIR) $$(NAPLIB),,g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/help
	${TAR} --directory ${WRKSRC}/teknap-help -cf - . | \
	${TAR} --directory ${DOCSDIR}/help -xf -
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%DOCSDIR%%:${DOCSDIR}:g"
	@${ECHO}
.endif

.include <bsd.port.post.mk>
