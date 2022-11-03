PORTNAME=	olm
DISTVERSION=	3.2.13
CATEGORIES=	security

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Double Ratchet cryptographic ratchet in C++
WWW=		https://gitlab.matrix.org/matrix-org/olm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang cpe
CPE_VENDOR=	matrix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.matrix.org/
GL_ACCOUNT=	matrix-org
GL_COMMIT=	6d767aaf29bdf15571c2ef4d3f8f9e953de03733

PLIST_SUB=	SOVER=${DISTVERSION}

CMAKE_OFF=	OLM_TESTS

.include <bsd.port.mk>
