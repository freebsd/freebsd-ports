PORTNAME=	Quaternion
DISTVERSION=	0.0.97.1
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies
WWW=		https://github.com/quotient-im/Quaternion/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libsecret-1.so:security/libsecret \
		libolm.so:security/olm
BUILD_DEPENDS=	libquotient>=0.9.3:net-im/libquotient
# Quotient is a static lib, doesn't need to be in RUN_DEPENDS

USES=		cmake compiler:c++20-lang qt:6 tar:xz
USE_QT=		base declarative multimedia \
		tools:build

CMAKE_ON=	BUILD_WITH_QT6

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im

.include <bsd.port.mk>
