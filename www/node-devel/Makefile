# $FreeBSD$

PORTNAME=	node
PORTVERSION=	0.11.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 javascript for client and server

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

MAN1=		node.1

USES=		gmake
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	2.7

CONFLICTS=	node-0.[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} --without-npm --shared-zlib
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
REINPLACE_ARGS=	-i ''

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900033 && exists(/usr/bin/clang)
CC=	clang
CXX=	clang++
GYP_DEFINES+=	clang=1
.else
USE_GCC?=	yes
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp

post-install:
	${MKDIR} ${PREFIX}/lib/node_modules/
	${TOUCH} ${PREFIX}/lib/node_modules/.keepme
	${CHMOD} ${MANMODE} ${PREFIX}/man/man1/node.1
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: If you need npm (Node Package Manager), please install www/npm."
	@${ECHO_MSG}

.include <bsd.port.mk>
