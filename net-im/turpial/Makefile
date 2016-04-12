# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	turpial
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	net-im python
MASTER_SITES=	http://files.turpial.org.ve/sources/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twitter client written in Python

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:devel/py-notify \
	${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.7:devel/py-setproctitle \
	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.1:devel/py-Jinja2 \
	${PYTHON_PKGNAMEPREFIX}libturpial>=1.7.0:net-im/py-libturpial

USES=		pyqt:4 python:2
USE_PYQT=	core_run gui_run network_run phonon_run webkit_run
USE_PYTHON=	distutils autoplist
INSTALLS_ICONS=	yes

LOCALES_DIR=	ca de eo es fr it ja pt_BR pt_PT ru_RU tr

post-extract:
# setuptools doesn't exclude these directories
.for dir in unity gtk
	@${RM} -Rf ${WRKSRC}/turpial/ui/${dir}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/turpial/ui/lang.py

post-build:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} setup.py compile_catalog --directory turpial/i18n

post-install:
.for dir in ${LOCALES_DIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${dir}/LC_MESSAGES
	@cd ${WRKSRC}/turpial/i18n && \
		${INSTALL_DATA} ${dir}/LC_MESSAGES/${PORTNAME}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${dir}/LC_MESSAGES
.endfor

.include <bsd.port.mk>
