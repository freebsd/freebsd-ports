# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	1.7.5
CATEGORIES=	sysutils python
MASTER_SITES=	https://github.com/nicolargo/glances/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.0.0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}psutil121>=1.2.1:${PORTSDIR}/sysutils/py-psutil121

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	Glances

NLS_TRANSLATIONS=	es fr it pt_BR zh_CN
NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/glances
	${INSTALL_DATA} ${WRKSRC}/conf/glances.conf ${STAGEDIR}${PREFIX}/etc/glances/glances.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/glances.1 ${STAGEDIR}${MANPREFIX}/man/man1/
.for lang in ${NLS_TRANSLATIONS}
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}/LC_MESSAGES/glances.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor

.include <bsd.port.mk>
