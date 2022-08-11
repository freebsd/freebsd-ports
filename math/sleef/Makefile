PORTNAME=	sleef
DISTVERSION=	3.5.0
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*} || ${ARCH:Marmv?}
PLIST_SUB+=	GNUABI="@comment "
.else
PLIST_SUB+=	GNUABI=""
.endif

.include <bsd.port.mk>
