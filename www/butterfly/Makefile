# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	butterfly
PORTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@rawbw.com
COMMENT=	Web terminal based on websocket and tornado

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}libsass>0:www/py-libsass

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
USE_RC_SUBR=	butterfly
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-install:
	@${REINPLACE_CMD} -i '' -e "s|^butterfly_dir = os.path.join(ev, 'butterfly')|butterfly_dir = '${PREFIX}/etc/butterfly'|g" \
		${STAGEDIR}${PREFIX}/bin/butterfly.server.py
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/butterfly/ssl
	${INSTALL_DATA} ${WRKSRC}/butterfly/butterfly.conf.default ${STAGEDIR}${ETCDIR}/butterfly.conf.sample

.include <bsd.port.mk>
