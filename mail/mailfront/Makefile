# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	mailfront
PORTVERSION=	2.01
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail server network protocol front-ends

LIB_DEPENDS=	libcvm-v2client.so:security/cvm

OPTIONS_DEFINE=	LUA DOCS

OPTIONS_DEFAULT=LUA
OPTIONS_SUB=	yes

USES=		qmail:vars

CFLAGS+=	-I${CVM_INC}
CFLAGS_SO=	${CFLAGS} -fPIC -shared -L${CVM_LIB}
LDFLAGS+=	-g -L${CVM_LIB}
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
CVM_INC=	${LOCALBASE}/include
CVM_LIB=	${LOCALBASE}/lib
MODULES_DIR=	${PREFIX}/libexec/${PORTNAME}

ALL_TARGET=	all
LATE_INSTALL_ARGS=	install_prefix=${STAGEDIR}

DOCS=		NEWS README TODO *.html

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA}
ALL_TARGET+=	lua
USES+=		lua:51
CFLAGS+=	-I${LUA_INCDIR}
CFLAGS_SO+=	-L${LUA_LIBDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.endif

LDFLAGS+=	-rdynamic

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${PREFIX}/include"	> ${WRKSRC}/conf-include
	${ECHO_CMD} "${MODULES_DIR}"	> ${WRKSRC}/conf-modules
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${CFLAGS_SO}"> ${WRKSRC}/conf-ccso
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs
	${ECHO_CMD} "${QMAIL_PREFIX}"	> ${WRKSRC}/conf-qmail

post-patch:
	@${REINPLACE_CMD} 's,-llua,-llua-${LUA_VER},' ${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
