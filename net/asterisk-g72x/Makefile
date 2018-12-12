# $FreeBSD$

PORTNAME=	g72x
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://asterisk.hosting.lv/src/
DISTNAME=	asterisk-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	G.729 codec for Asterisk PBX

LIB_DEPENDS=	libbcg729.so:audio/bcg729

FLAVORS=			asterisk13 asterisk15 asterisk16
FLAVOR?=			${FLAVORS[1]}

asterisk13_PKGNAMEPREFIX=	asterisk13-
asterisk13_CONFLICTS_INSTALL=	asterisk15-g72x asterisk16-g72x
asterisk13_BUILD_DEPENDS=	asterisk:net/asterisk13
asterisk13_RUN_DEPENDS=		asterisk:net/asterisk13
asterisk15_CONFIGURE_ARGS=	--with-asterisk130

asterisk15_PKGNAMEPREFIX=	asterisk15-
asterisk15_CONFLICTS_INSTALL=	asterisk13-g72x asterisk16-g72x
asterisk15_BUILD_DEPENDS=	asterisk:net/asterisk15
asterisk15_RUN_DEPENDS=		asterisk:net/asterisk15
asterisk15_CONFIGURE_ARGS=	--with-asterisk150

asterisk16_PKGNAMEPREFIX=	asterisk16-
asterisk16_CONFLICTS_INSTALL=	asterisk13-g72x asterisk15-g72x
asterisk16_BUILD_DEPENDS=	asterisk:net/asterisk16
asterisk16_RUN_DEPENDS=		asterisk:net/asterisk16
asterisk16_CONFIGURE_ARGS=	--with-asterisk160

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bcg729
USES=		autoreconf compiler libtool localbase tar:bzip2

PLIST_FILES=	lib/asterisk/modules/codec_g729.so

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-build:
	${STRIP_CMD} ${WRKSRC}/.libs/codec_g729.so

.include <bsd.port.post.mk>
