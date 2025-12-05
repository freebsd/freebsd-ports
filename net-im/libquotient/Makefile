PORTNAME=	libquotient
DISTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	net-im

PATCH_SITES=	https://github.com/quotient-im/libQuotient/commit/
PATCHFILES+=	861f520092c9c915356234e85c0744097a155822.patch:-p1 # Fix build with Qt 6.10
PATCHFILES+=	ea83157eed37ff97ab275a5d14c971f0a5a70595.patch:-p1 # Fix configure of consumers with Qt 6.10
PATCHFILES+=	cbf984531426e9bd533dbae9dd15944271c1012e.patch:-p1 # Fix configure of consumers with Qt 6.10

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies
WWW=		https://github.com/quotient-im/libQuotient

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libolm.so:security/olm

USES=		cmake compiler:c++20-lang qt:6 tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_PROJECT=	libQuotient
USE_QT=		base
CMAKE_OFF=	Quotient_INSTALL_TESTS

CONFLICTS=	libqmatrixclient\*

.include <bsd.port.mk>
