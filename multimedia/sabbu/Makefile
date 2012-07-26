# New ports collection makefile for:	sabbu
# Date created:		2005-04-14
# Whom:			dikr.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sabbu
PORTVERSION=	0.3.0
PORTREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sabbu%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program used to time subtitles

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		sndfile:${PORTSDIR}/audio/libsndfile

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	yes

USE_GNOME=	gtk20
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lswscale

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	WITH_NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	WITH_NLS=""
.endif

ASPELL_PORT?=	textproc/aspell
.if !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
PLIST_SUB+=	WITH_ASPELL=""
.else
PLIST_SUB+=	WITH_ASPELL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.include <bsd.port.post.mk>
