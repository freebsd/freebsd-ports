# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	mailfront
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/ \
		http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Mail server network protocol front-ends

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcvm-v2client.so:security/cvm \
		libbg.so:devel/bglibs

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

PORTDOCS=	NEWS README TODO *.html

LDFLAGS+=	-rdynamic

OPTIONS_DEFINE=	LUA DOCS
OPTIONS_DEFAULT=LUA
OPTIONS_SUB=	yes

LUA_ALL_TARGET=	lua
LUA_USES=	lua
LUA_VARS=	CFLAGS+=-I${LUA_INCDIR} LUA_CFLAGS_SO+=-L${LUA_LIBDIR} LUA_LDFLAGS+=-L${LUA_LIBDIR}

CPPFLAGS+=      -I${LUA_INCDIR}
CFLAGS+=        -DHAVE_LUASCRIPT
LDFLAGS+=       -L${LUA_LIBDIR} -llua-${LUA_VER}
USES+=          lua:51

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
	@${REINPLACE_CMD} 's,-llua-,-llua-${LUA_VER},' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
