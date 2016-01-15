# $FreeBSD$

PORTNAME=	easy-rsa
DISTVERSION=	2.2.2
CATEGORIES=	security net-mgmt
PKGNAMESUFFIX=	2

# Eric F. Crist <ecrist@secure-computing.net> does not require my
# approval for changes to this package. -- mandree@FreeBSD.org
MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Small RSA key management package based on openssl

LICENSE=	GPLv2

CONFLICTS_INSTALL=easy-rsa-3*

USE_GITHUB=	yes
GH_ACCOUNT=	OpenVPN

GNU_CONFIGURE=	yes
USES=		autoreconf

WRKSRC=		${WRKDIR}/easy-rsa-${DISTVERSION}

.include <bsd.port.mk>
