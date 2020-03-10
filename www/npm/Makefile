# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	npm
PORTVERSION=	6.12.1
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/lib/node_modules/npm/LICENSE

RUN_DEPENDS=	gmake:devel/gmake

USES=		cpe python:2.7,run shebangfix tar:xz

NO_ARCH=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i ''

CONFLICTS_INSTALL?=	npm-node10 npm-node12 npm-node8

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE NODE10 NODE12
OPTIONS_DEFAULT=NODE
NODE_DESC=	Use Node.js 13.x (www/node) as backend
NODE10_DESC=	Use Node.js 10.x (www/node10) as backend
NODE12_DESC=	Use Node.js 12.x (www/node12) as backend

CPE_VENDOR=	npmjs
CPE_PRODUCT=	node_packaged_modules

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	lib/node_modules/npm/node_modules/node-gyp/gyp/samples/samples

NODE_RUN_DEPENDS=	node>=0.8.0:www/node
NODE10_RUN_DEPENDS=	node10>=0.8.0:www/node10
NODE12_RUN_DEPENDS=	node12>=0.8.0:www/node12

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# Workaround for kernel bug 178881
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bug-178881
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/etc/man.d/npm.conf
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/lib/node_modules/npm/node_modules/node-gyp/gyp/gyp
	@${FIND} ${WRKSRC}/ -name '*.sh' -exec ${REINPLACE_CMD} -e '1 s|/usr/local|${LOCALBASE}|' {} +

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/

.include <bsd.port.post.mk>
