PORTNAME=	g72x
DISTVERSION=	1.4.4
CATEGORIES=	net
MASTER_SITES=	http://asterisk.hosting.lv/src/
DISTNAME=	asterisk-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	G.729 codec for Asterisk PBX
WWW=		http://asterisk.hosting.lv/

LICENSE=	GPLv3+

LIB_DEPENDS=	libbcg729.so:audio/bcg729

FLAVORS=	asterisk18 asterisk20 asterisk22
FLAVOR?=	${FLAVORS:[3]}

${FLAVOR}_PKGNAMEPREFIX=	${FLAVOR}-
${FLAVOR}_BUILD_DEPENDS=	asterisk:net/${FLAVOR}
${FLAVOR}_RUN_DEPENDS=		asterisk:net/${FLAVOR}

USES=		autoreconf compiler:c11 libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-asterisk160 --with-bcg729

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C|(.+)|\1-${PORTNAME}|}

PLIST_FILES=	lib/asterisk/modules/codec_g729.so

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-fblocks
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/asterisk/modules/codec_g729.so

.include <bsd.port.post.mk>
