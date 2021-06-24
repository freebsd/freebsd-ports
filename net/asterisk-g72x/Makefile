PORTNAME=	g72x
PORTVERSION=	1.4.3
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://asterisk.hosting.lv/src/
DISTNAME=	asterisk-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	G.729 codec for Asterisk PBX

LIB_DEPENDS=	libbcg729.so:audio/bcg729

FLAVORS=			asterisk18 asterisk16 asterisk13
FLAVOR?=			${FLAVORS:[1]}

asterisk13_PKGNAMEPREFIX=	asterisk13-
asterisk13_CONFLICTS_INSTALL=	asterisk16-g72x asterisk18-g72x
asterisk13_BUILD_DEPENDS=	asterisk:net/asterisk13
asterisk13_RUN_DEPENDS=		asterisk:net/asterisk13
.if ${FLAVOR} == asterisk13
CONFIGURE_ARGS+=		--with-asterisk130
.endif

asterisk16_PKGNAMEPREFIX=	asterisk16-
asterisk16_CONFLICTS_INSTALL=	asterisk13-g72x asterisk18-g72x
asterisk16_BUILD_DEPENDS=	asterisk:net/asterisk16
asterisk16_RUN_DEPENDS=		asterisk:net/asterisk16
.if ${FLAVOR} == asterisk16
CONFIGURE_ARGS+=		--with-asterisk160
.endif

asterisk18_PKGNAMEPREFIX=	asterisk18-
asterisk18_CONFLICTS_INSTALL=	asterisk13-g72x asterisk16-g72x
asterisk18_BUILD_DEPENDS=	asterisk:net/asterisk18
asterisk18_RUN_DEPENDS=		asterisk:net/asterisk18
.if ${FLAVOR} == asterisk18
CONFIGURE_ARGS+=		--with-asterisk160
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-bcg729
USES=		autoreconf compiler:c11 libtool localbase tar:bzip2

PLIST_FILES=	lib/asterisk/modules/codec_g729.so

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-build:
	${STRIP_CMD} ${WRKSRC}/.libs/codec_g729.so

.include <bsd.port.post.mk>
