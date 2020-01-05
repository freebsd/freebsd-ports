# $FreeBSD$

PORTNAME=	reggae
PORTVERSION=	0.1.9
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	Powerful DevOps solution heavily relaying on CBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/cbsd:sysutils/cbsd \
		curl:ftp/curl \
		sudo:security/sudo

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cbsd

.include <bsd.port.mk>
