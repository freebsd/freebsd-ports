PORTNAME=	bmd-plugin-hookcmd
DISTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	BMD plugin hookcmd
WWW=		https://github.com/yuichiro-naito/bmd-plugin-hookcmd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	bhyve runs on amd64 only

BUILD_DEPENDS=	bmd>0:sysutils/bmd
RUN_DEPENDS=	bmd>0:sysutils/bmd

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

pre-install:
	${MKDIR} ${STAGEDIR}/${LOCALBASE}/libexec/bmd

.include <bsd.port.mk>
