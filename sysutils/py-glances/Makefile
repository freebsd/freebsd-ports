# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	glances
PORTVERSION=	1.7.1
CATEGORIES=	sysutils python
MASTER_SITES=	https://github.com/nicolargo/glances/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	CLI curses based monitoring tool for GNU/Linux and BSD OS

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.0.0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=0.4.1:${PORTSDIR}/sysutils/py-psutil

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
FETCH_ARGS=	-pRr
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	Glances

OPTIONS_DEFINE=	NLS

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		glances.1
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
TRANSLATIONS=	es fr it pt_BR zh_CN
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/glances
	${INSTALL_DATA} ${WRKSRC}/glances/conf/glances.conf ${PREFIX}/etc/glances/glances.conf.sample
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/docs/man/glances.1 ${MANPREFIX}/man/man1/
.endif
.if ${PORT_OPTIONS:MNLS}
.for lang in ${TRANSLATIONS}
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}/LC_MESSAGES/glances.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor
.endif

.include <bsd.port.mk>
