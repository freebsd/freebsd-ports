PORTNAME=	rnp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	1
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

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rnpgp
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=on \
		-DBUILD_TESTING=off

pre-configure:
		${CP} ${FILESDIR}/version.cmake ${WRKSRC}/cmake/
		${REINPLACE_CMD} 's/%%DISTVERSION%%/${DISTVERSION}/' \
					${WRKSRC}/cmake/version.cmake

.include <bsd.port.mk>
