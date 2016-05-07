# $FreeBSD$

PORTNAME=	asterisk-g72x
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://asterisk.hosting.lv/src/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	G.729 codec for Asterisk PBX

LIB_DEPENDS=	libbcg729.so:audio/bcg729

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bcg729
USES=		autoreconf compiler libtool tar:bzip2
NO_OPTIONS_SORT=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/asterisk/modules/codec_g729.so

OPTIONS_SINGLE=	ASTVER
OPTIONS_SINGLE_ASTVER=	ASTERISK18 ASTERISK11 ASTERISK13

OPTIONS_DEFAULT=	ASTERISK11

ASTERISK18_DESC=	Depend on Asterisk 1.8
ASTERISK11_DESC=	Depend on Asterisk 11
ASTERISK13_DESC=	Depend on Asterisk 13

ASTERISK18_BUILD_DEPENDS=	asterisk:net/asterisk
ASTERISK18_RUN_DEPENDS=	asterisk:net/asterisk
ASTERISK18_CONFIGURE_ON=	--with-asterisk18
ASTERISK11_BUILD_DEPENDS=	asterisk:net/asterisk11
ASTERISK11_RUN_DEPENDS=	asterisk:net/asterisk11
ASTERISK11_CONFIGURE_ON=	--with-asterisk100
ASTERISK13_BUILD_DEPENDS=	asterisk:net/asterisk13
ASTERISK13_RUN_DEPENDS=	asterisk:net/asterisk13
ASTERISK13_CONFIGURE_ON=	--with-asterisk130

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-build:
	${STRIP_CMD} ${WRKSRC}/.libs/codec_g729.so

.include <bsd.port.post.mk>
