# $FreeBSD$

PORTNAME=	asterisk-g72x
PORTVERSION=	1.4.2
CATEGORIES=	net
MASTER_SITES=	http://asterisk.hosting.lv/src/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	G.729 codec for Asterisk PBX

LIB_DEPENDS=	libbcg729.so:audio/bcg729
BUILD_DEPENDS=	asterisk:net/asterisk13
RUN_DEPENDS=	asterisk:net/asterisk13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bcg729 \
		--with-asterisk130
USES=		autoreconf compiler libtool localbase tar:bzip2

PLIST_FILES=	lib/asterisk/modules/codec_g729.so

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-build:
	${STRIP_CMD} ${WRKSRC}/.libs/codec_g729.so

.include <bsd.port.post.mk>
