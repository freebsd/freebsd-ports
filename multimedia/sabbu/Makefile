# New ports collection makefile for:	sabbu
# Date created:		2005-04-14
# Whom:			dikr.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sabbu
PORTVERSION=	0.3.0
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sabbu%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program used to time subtitles

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		sndfile:${PORTSDIR}/audio/libsndfile

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes

USE_GNOME=	gtk20
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lswscale
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

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

.include <bsd.port.mk>
