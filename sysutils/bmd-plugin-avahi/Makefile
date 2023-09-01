PORTNAME=	bmd-plugin-avahi
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	BMD plugin avahi
WWW=		https://github.com/yuichiro-naito/bmd-plugin-avahi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Because bhyve runs on amd64 only.
ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bmd>0:sysutils/bmd
RUN_DEPENDS=	bmd>0:sysutils/bmd \
		avahi-app>0:net/avahi-app

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

pre-install:
	${MKDIR} ${STAGEDIR}/${LOCALBASE}/libexec/bmd

.include <bsd.port.mk>
