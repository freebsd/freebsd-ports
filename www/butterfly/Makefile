# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	butterfly
PORTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web terminal based on websocket and tornado

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libsass>0:www/py-libsass@${FLAVOR}

USES=		python
# Can't use concurrent here, it changes ETCDIR, and breaks post-install.
USE_PYTHON=	autoplist distutils optsuffix
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
