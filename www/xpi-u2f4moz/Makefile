# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	u2f4moz
DISTVERSION=	v1.0
CATEGORIES=	www
PKGNAMEPREFIX=	xpi-

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	U2F support extension for Firefox

LICENSE=	LGPL21

BROKEN_FreeBSD_9=	does not build

CMAKE_SOURCE_PATH=	c_src

FIREFOX_EXTENSIONS_DIR=	lib/firefox/browser/extensions

GH_ACCOUNT=	prefiks

PLIST_SUB=	SYSTEM_PROCESSOR=${SYSTEM_PROCESSOR}

SYSTEM_PROCESSOR=	x86

USE_GITHUB=	yes
USES=		cmake iconv pkgconfig

XPI_DIR=	lib/xpi
XPI_ID=		u2f4moz@prefiks.org

post-patch:
	@${SED} -i.bak -e 's,%%XPI_DIR%%,${XPI_DIR},1' \
		-e 's,%%XPI_ID%%,${XPI_ID},1' ${WRKSRC}/c_src/CMakeLists.txt

post-install:
	(cd ${WRKSRC}/ext && \
	${COPYTREE_SHARE} . ${STAGEDIR}/${PREFIX}/${XPI_DIR}/${XPI_ID} && \
	${MKDIR} ${STAGEDIR}/${PREFIX}/${FIREFOX_EXTENSIONS_DIR})
	(cd ${STAGEDIR}/${PREFIX}/${FIREFOX_EXTENSIONS_DIR} && \
	${LN} -s ../../../xpi/${XPI_ID} ${XPI_ID})

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
SYSTEM_PROCESSOR=	x86_64
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-freebsd9
.endif

.include <bsd.port.post.mk>
