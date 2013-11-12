# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	smpeg2
PORTVERSION=	2.0.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.libsdl.org/projects/smpeg/release/ \
		http://rsync.macports.org/smpeg2/

MAINTAINER=	wulf@mail.mipt.ru
COMMENT=	Free MPEG1 video player library with sound support

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_SDL=	sdl2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PLAYMPEG
OPTIONS_DEFAULT=
PLAYMPEG_DESC=	Build plaympeg binary (conficts with smpeg)
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--enable-mmx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLAYMPEG}
CONFLICTS+=	smpeg
.endif

post-patch:
.if ! ${PORT_OPTIONS:MPLAYMPEG}
	@${REINPLACE_CMD} -e '/^bin_PROGRAMS =/s/plaympeg$$(EXEEXT)// ; \
		/^man_MANS =/s/plaympeg\.1//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
