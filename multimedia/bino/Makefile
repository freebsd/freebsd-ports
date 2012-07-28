# New ports collection makefile for:	bino
# Date created:		2012-03-12
# Whom:			Mykola Dzham <i@levsha.me>
#
# $FreeBSD$
#

PORTNAME=	bino
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.savannah.nongnu.org/releases/bino/ http://levsha.me/ports/distfiles/

MAINTAINER=	i@levsha.me
COMMENT=	3D video player with multi-display support

LICENSE=	GPLv3

FETCH_ARGS=	-Fpr
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	build
INSTALLS_ICONS=	yes
USE_QT4=	moc_build opengl rcc_build

# no port fow equalizer now, lirc detecting not working
CONFIGURE_ARGS+=	--without-equalizer --without-liblircclient --docdir=${DOCSDIR}

LIB_DEPENDS+=	ass.5:${PORTSDIR}/multimedia/libass \
		avformat.1:${PORTSDIR}/multimedia/ffmpeg \
		GLEW.1:${PORTSDIR}/graphics/glew \
		openal.1:${PORTSDIR}/audio/openal-soft

MAN1=	bino.1
INFO=	bino

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# fixes build on non UTF-8 enviroments
post-patch:
	@${REINPLACE_CMD} -e 's|echo $<|LANG=C; LC_ALL=C; &|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
