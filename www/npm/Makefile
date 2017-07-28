# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	npm
PORTVERSION=	5.3.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager

LICENSE=	MIT

RUN_DEPENDS=	gmake:devel/gmake \
		node>=0.8.0:www/node

CONFLICTS_INSTALL=	npm2 npm3 npm4

NO_ARCH=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i ''
USES=		cpe python:2,run shebangfix tar:xz

CPE_VENDOR=	npmjs
CPE_PRODUCT=	node_packaged_modules

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	lib/node_modules/npm/node_modules/node-gyp/gyp/samples/samples

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
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
