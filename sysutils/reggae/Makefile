PORTNAME=	reggae
DISTVERSION=	0.2.3
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	Powerful DevOps solution heavily relaying on CBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/cbsd:sysutils/cbsd \
		sudo:security/sudo

USE_GITHUB=	yes
GH_ACCOUNT=	cbsd
USE_RC_SUBR=	reggae reggae_pf

NO_ARCH=	yes

.include <bsd.port.mk>
