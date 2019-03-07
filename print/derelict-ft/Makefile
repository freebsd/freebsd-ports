# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	derelict-ft
PORTVERSION=	1.1.3
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	print

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Dynamic binding to the FreeType library for the D lang

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libDerelictUtil.a:devel/derelict-util

USE_GITHUB=	yes
GH_ACCOUNT=	DerelictOrg
GH_PROJECT=	DerelictFT

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

post-patch:
	@${REINPLACE_CMD} -e '13,15d' ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libDerelictFT.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/source && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
