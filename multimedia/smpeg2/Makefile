PORTNAME=	smpeg2
PORTVERSION=	2.0.0
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	https://www.libsdl.org/projects/smpeg/release/ \
		https://distfiles.macports.org/smpeg2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free MPEG1 video player library with sound support
WWW=		https://icculus.org/smpeg/

LICENSE=	MIT LGPL20+
LICENSE_COMB=	multi

USES=		compiler:features libtool sdl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
CFLAGS+=	${COMPILER_FEATURES:Mc++11:C/.+/-Wno-error=narrowing/}
USE_SDL=	sdl2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PLAYMPEG
OPTIONS_DEFAULT=
PLAYMPEG_DESC=	Build plaympeg binary (conficts with smpeg)
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--enable-mmx

PLAYMPEG_CONFLICTS_INSTALL=	smpeg
PLAYMPEG_VARS=	LICENSE+=GPLv2+

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CPPFLAGS+=  -Dregister=
.endif

post-patch-PLAYMPEG-off:
	@${REINPLACE_CMD} -e '/^bin_PROGRAMS =/s/plaympeg$$(EXEEXT)// ; \
		/^man_MANS =/s/plaympeg\.1//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
