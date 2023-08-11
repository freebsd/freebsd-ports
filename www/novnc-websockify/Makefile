PORTNAME=	websockify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Websockify implementation for noVNC
WWW=		https://github.com/novnc/websockify

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYNUMPY} \
		novnc>0:www/novnc

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	novnc
GH_PROJECT=	websockify

SHEBANG_FILES=	run

NO_ARCH=	yes
NO_BUILD=	yes
TARGET_DIR=	${PREFIX}/libexec/novnc/utils/websockify

do-install:
	@${MKDIR} ${STAGEDIR}${TARGET_DIR}
	cd ${WRKSRC} && ${RM} .gitignore .gitmodules .travis.yml
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TARGET_DIR}
	@${CHMOD} +x ${STAGEDIR}${TARGET_DIR}/run
	@${CHMOD} +x ${STAGEDIR}${TARGET_DIR}/rebind

.include <bsd.port.mk>
