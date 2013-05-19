# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	mailfront
PORTVERSION=	1.21
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	tarkhil@over.ru
COMMENT=	Mail server network protocol front-ends

LIB_DEPENDS=	cvm-v2client:${PORTSDIR}/security/cvm

OPTIONS_DEFINE=	LUA

OPTIONS_DEFAULT=	LUA

USES=		qmail:vars

CFLAGS+=	-I${CVM_INC}
CFLAGS_SO=	${CFLAGS} -fPIC -shared -L${CVM_LIB}
LDFLAGS+=	-g -L${CVM_LIB}
BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
CVM_INC=	${LOCALBASE}/include
CVM_LIB=	${LOCALBASE}/lib
MODULES_DIR=	${PREFIX}/libexec/${PORTNAME}

DOCS=		NEWS README TODO *.html

.include <bsd.port.pre.mk>

ALL_TARGET=	all

.if ${PORT_OPTIONS:MLUA}
ALL_TARGET+=	lua
USE_LUA=	yes
CFLAGS+=	-I${LUA_INCDIR}
CFLAGS_SO+=	-L${LUA_LIBDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
PLIST_SUB+=	LUA=""
.else
PLIST_SUB+=	LUA="@comment "
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

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
