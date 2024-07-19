PORTNAME=	keepassrpc
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=v
CATEGORIES=	security
PKGNAMEPREFIX=	keepass-plugin-

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	KeePass plugin which facilitates the Kee Firefox plugin
WWW=		https://www.kee.pm/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	keepass>0:security/keepass \
		msbuild:devel/msbuild
LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus

USES=		cpe mono
CPE_VENDOR=	kee
USE_GITHUB=	yes
GH_ACCOUNT=	kee-org

DATADIR=	${PREFIX}/share/keepass/Plugins
NO_ARCH=	yes

OPTIONS_DEFINE=	DEBUG
DEBUG_VARS=	config=Debug
DEBUG_VARS_OFF=	config=Release

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/msbuild /t:KeePassRPC /p:Configuration=${CONFIG})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/KeePassRPC/bin/${CONFIG} && \
		${RM} ./KeePass.exe && \
		${RM} ./KeePass.exe.config && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
