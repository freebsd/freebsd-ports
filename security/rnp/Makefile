# $FreeBSD$

PORTNAME=	rnp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	RNP is a set of OpenPGP (RFC4880) tools

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE OCB_Patent
LICENSE_COMB=	multi
LICENSE_NAME_OCB_Patent=	OCB Patent License for Ribose Inc.
LICENSE_FILE_OCB_Patent=	${WRKSRC}/LICENSE-OCB.md
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_OCB_Patent=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

LIB_DEPENDS=	libbotan-2.so:security/botan2 \
		libjson-c.so:devel/json-c

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	rnpgp

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=on \
		-DBUILD_TESTING=off

.include <bsd.port.mk>
