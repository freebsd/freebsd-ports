# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flower
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
CATEGORIES=	net

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Label-based networking daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarpc.so:devel/arpc \
		libjsoncpp.so:devel/jsoncpp

USES=		cmake localbase:ldflags tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	NuxiNL

CFLAGS+=	-I${LOCALBASE}/include/jsoncpp

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100511
IGNORE=		requires various C++17 features
.endif

# Require the unit tests to pass prior to installing.
post-build:
	@trap '' PIPE && ${WRKSRC}/flower_unittests

.include <bsd.port.post.mk>
