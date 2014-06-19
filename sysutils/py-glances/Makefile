# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	2.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.0.0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.0.0:${PORTSDIR}/sysutils/py-psutil

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nicolargo
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	2484bea

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

PLIST_FILES=	%%ETCDIR%%/glances.conf.sample \
		man/man1/glances.1.gz \
		%%NLS%%share/locale/de/LC_MESSAGES/glances.mo
PLIST_DIRS=	etc/glances

NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/glances
	${INSTALL_DATA} ${WRKSRC}/conf/glances.conf ${STAGEDIR}${PREFIX}/etc/glances/glances.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/glances.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/i18n/de/LC_MESSAGES/glances.mo \
		${STAGEDIR}${PREFIX}/share/locale/de/LC_MESSAGES/

.include <bsd.port.mk>
