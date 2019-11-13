# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	denyhosts
PORTVERSION=	3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Script to thwart ssh and imap attacks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipaddr>=0:devel/py-ipaddr@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
USE_RC_SUBR=	denyhosts

PLIST_FILES=	"@sample etc/denyhosts.conf.sample"
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON=${PYTHON_CMD}

USE_GITHUB=	yes

SHEBANG_FILES=	daemon-control-dist \
		plugins/test_deny.py \
		scripts/restricted_from_invalid.py \
		scripts/restricted_from_passwd.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/daemon-control-dist ${WRKSRC}/denyhosts.conf ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' ${WRKSRC}/daemon-control-dist

post-install:
	${INSTALL_DATA} ${WRKSRC}/denyhosts.conf ${STAGEDIR}${PREFIX}/etc/denyhosts.conf.sample

.include <bsd.port.mk>
