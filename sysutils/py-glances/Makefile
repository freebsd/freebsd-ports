# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	3.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0.15.2:devel/py-coverage@${PY_FLAVOR}

USES=		python:-3.6
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

GH_ACCOUNT=	nicolargo

NO_ARCH=	yes

PLIST_FILES=	${ETCDIR}/glances.conf.sample \
		man/man1/glances.1.gz

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/glances.conf ${STAGEDIR}${ETCDIR}/glances.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/man/glances.1 ${STAGEDIR}${MANPREFIX}/man/man1/

do-test:
	@(cd ${WRKSRC} && ${SETENV} coverage-${PYTHON_VER} run --source=glances unitest.py)

.include <bsd.port.mk>
