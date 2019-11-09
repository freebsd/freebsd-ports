# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	3.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

GH_ACCOUNT=	nicolargo

NO_ARCH=	yes

PLIST_FILES=	${ETCDIR}/glances.conf.sample \
		man/man1/glances.1.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/glances
	${INSTALL_DATA} ${WRKSRC}/conf/glances.conf ${STAGEDIR}${PREFIX}/etc/glances/glances.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/man/glances.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
