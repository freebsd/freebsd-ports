PORTNAME=	reggae
DISTVERSION=	0.3.11
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	Powerful DevOps solution heavily relaying on CBSD
WWW=		https://github.com/cbsd/reggae

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	sudo:security/sudo

USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
USE_RC_SUBR=	reggae reggae_pf

NO_ARCH=	yes

.include <bsd.port.mk>
