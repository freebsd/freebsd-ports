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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:${PORTSDIR}/devel/py-babel
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:${PORTSDIR}/devel/py-notify \
	${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.7:${PORTSDIR}/devel/py-setproctitle \
	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.1:${PORTSDIR}/devel/py-Jinja2 \
	${PYTHON_PKGNAMEPREFIX}libturpial>=1.7.0:${PORTSDIR}/net-im/py-libturpial

USES=		python:2
USE_PYTHON=	distutils autoplist
INSTALLS_ICONS=	yes

PYQT4_PORTS=	core gui network phonon webkit

.include "${.CURDIR}/../../devel/py-qt4/bsd.pyqt.mk"

.for component in ${PYQT4_PORTS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-${component}>=0:${PORTSDIR}/${${component}_PORT}
.endfor

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
