PORTNAME=	greenbone-feed-sync
DISTVERSION=	25.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	new script for downloading the Greenbone Community Feed
WWW=		https://github.com/greenbone/greenbone-feed-sync

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rich>=13.2.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shtab>=1.6.5:devel/py-shtab@${PY_FLAVOR} \
		${PY_TOMLI} \
		rsync:net/rsync

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	pep517

NO_ARCH=	yes

USERS=		gvm
GROUPS=		${USERS}

post-extract:
	${MV} ${WRKSRC}/tests ${WRKSRC}/greenbone/

post-patch:
	@${RM} ${WRKSRC}/greenbone/feed/sync/config.py.orig
	@${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/greenbone/feed/sync/config.py

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gvm
	@${MKDIR} ${STAGEDIR}/var/lib/gvm
	@${MKDIR} ${STAGEDIR}/var/lib/openvas/plugins
	@${MKDIR} ${STAGEDIR}/var/lib/notus

.include <bsd.port.mk>
