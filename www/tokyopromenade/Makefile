# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	tokyopromenade
PORTVERSION=	0.9.22
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://fallabs.com/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Content management system

BUILD_DEPENDS=	tokyocabinet>=1.4.31:${PORTSDIR}/databases/tokyocabinet \
		fcgi-devkit>=0:${PORTSDIR}/www/fcgi
LIB_DEPENDS=	libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet
RUN_DEPENDS=	spawn-fcgi>=0:${PORTSDIR}/www/spawn-fcgi

OPTIONS_DEFINE=	LUA

CONFIGURE_ARGS=	--enable-fcgi
GNU_CONFIGURE=	yes
USES=		gmake lua compiler

SUB_FILES=	pkg-message

LUA_CONFIGURE_ENABLE+=	lua
LUA_LDFLAGS+=	-L${LUA_LIBDIR}
LUA_CFLAGS+=	-I${LUA_INCDIR}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang"
CFLAGS+=		-Wno-incompatible-pointer-types-discards-qualifiers
.endif

post-patch:
	${REINPLACE_CMD} -e "s/llua/llua-${LUA_VER}/g" ${WRKSRC}/configure

.include <bsd.port.post.mk>
