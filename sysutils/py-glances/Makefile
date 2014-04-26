# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	1.7.6
CATEGORIES=	sysutils python
MASTER_SITES=	https://github.com/nicolargo/glances/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.0.0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.0.0:${PORTSDIR}/sysutils/py-psutil

OPTIONS_DEFINE=	DOCS MANPAGES NLS
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

PLIST_FILES=	bin/glances \
		%%ETCDIR%%/glances.conf.sample \
		%%MANPAGES%%man/man1/glances.1.gz \
		%%NLS%%share/locale/es/LC_MESSAGES/glances.mo \
		%%NLS%%share/locale/fr/LC_MESSAGES/glances.mo \
		%%NLS%%share/locale/it/LC_MESSAGES/glances.mo \
		%%NLS%%share/locale/pt_BR/LC_MESSAGES/glances.mo \
		%%NLS%%share/locale/zh_CN/LC_MESSAGES/glances.mo
PLIST_DIRS=	etc/glances
PORTDOCS=	*

NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/glances
	${INSTALL_DATA} ${WRKSRC}/conf/glances.conf ${STAGEDIR}${PREFIX}/etc/glances/glances.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/glances.1 ${STAGEDIR}${MANPREFIX}/man/man1/
.for lang in es fr it pt_BR zh_CN
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}/LC_MESSAGES/glances.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor

.include <bsd.port.mk>
