# $FreeBSD$

PORTNAME=	easy-rsa
DISTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	security net-mgmt
PKGNAMESUFFIX=	2

# Eric F. Crist <ecrist@secure-computing.net> does not require my
# approval for changes to this package. -- mandree@FreeBSD.org
MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Small RSA key management package based on openssl

DEPRECATED=	Use easy-rsa 3 instead.
EXPIRATION_DATE=2019-06-23

LICENSE=	GPLv2

CONFLICTS_INSTALL=easy-rsa-3*

USE_GITHUB=	yes
GH_ACCOUNT=	OpenVPN

GNU_CONFIGURE=	yes
USES=		autoreconf

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/vars ${STAGEDIR}${DATADIR}/vars.sample

.include <bsd.port.mk>
