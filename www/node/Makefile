# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	node
PORTVERSION=	0.10.22
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 JavaScript for client and server

LICENSE=	MIT

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	2
USES=		gmake

CONFLICTS=	node-0.[02-9][0-9]* node-devel-0.[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} --without-npm
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e '1 s|${SETENV} python|${PYTHON_CMD}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|'python',|'${PYTHON_CMD}',|" \
		${WRKSRC}/deps/v8/build/common.gypi \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp \
		${WRKSRC}/deps/v8/src/d8.gyp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/deps/v8/build/common.gypi \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/node_modules/.keepme
	${CHMOD} ${MANMODE} ${STAGEDIR}${PREFIX}/man/man1/node.1
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: If you need npm (Node Package Manager), please install www/npm."
	@${ECHO_MSG}

.include <bsd.port.mk>
