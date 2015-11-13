# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	2.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=2.1.1:${PORTSDIR}/sysutils/py-psutil

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nicolargo
GH_TAGNAME=	v2.5

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PLIST_FILES=	%%ETCDIR%%/glances.conf.sample \
		man/man1/glances.1.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/glances
	${INSTALL_DATA} ${WRKSRC}/conf/glances.conf ${STAGEDIR}${PREFIX}/etc/glances/glances.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/glances.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
