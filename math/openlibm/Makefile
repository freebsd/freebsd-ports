# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	openlibm
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math
MASTER_SITES=	GH

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	High quality system independent, portable, open source libm

LICENSE=	MIT ISCL BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	JuliaLang
GH_PROJECT=	openlibm

USES=	gmake
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

MAKE_ENV+=	prefix=${PREFIX}

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	EXTRA_HEADER=""
.else
PLIST_SUB+=	EXTRA_HEADER="@comment "
.endif

TEST_TARGET=	check

.include <bsd.port.post.mk>
