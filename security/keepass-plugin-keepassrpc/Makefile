PORTNAME=	keepassrpc
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=v
CATEGORIES=	security
PKGNAMEPREFIX=	keepass-plugin-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KeePass plugin which facilitates the Kee Firefox plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	keepass>0:security/keepass
LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus

USES=		cpe mono
CPE_VENDOR=	kee
USE_GITHUB=	yes
GH_ACCOUNT=	kee-org

NO_ARCH=	yes
DATADIR=	${PREFIX}/share/keepass/Plugins

OPTIONS_DEFINE=	DEBUG
DEBUG_VARS=	config=Debug
DEBUG_VARS_OFF=	config=Release

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/xbuild /t:KeePassRPC /p:Configuration=${CONFIG})

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/KeePassRPC/bin/${CONFIG} && \
		${RM} ./KeePass.exe && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
