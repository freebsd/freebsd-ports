# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	ranger
PORTVERSION=	1.9.3
CATEGORIES=	sysutils python
MASTER_SITES=	https://ranger.github.io/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# Backport PR #1852 to fix runtime issues for environments that don't have
# sysutils/screen installed but TERM set to "screen".
PATCH_SITES=	https://github.com/ranger/ranger/commit/
PATCHFILES=	081e73152a9391211770fab56676d7d974413ae6.patch:-p1

MAINTAINER=	linpct@gmail.com
COMMENT=	File manager with VI key bindings

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		desktop-file-utils python shebangfix
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	doc/tools/*.py

NO_ARCH=	yes

post-extract:
	@${MV} ${WRKSRC}/doc/ranger.desktop ${WRKSRC}/doc/${PYTHON_PKGNAMEPREFIX}ranger.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|; \
		s|share/doc/ranger|${DOCSDIR}|; \
		s|ranger.desktop|${PYTHON_PKGNAMEPREFIX}ranger.desktop|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -Ee 's|Exec=(ranger)|Exec=\1-${PYTHON_VER}|' ${WRKSRC}/doc/${PYTHON_PKGNAMEPREFIX}ranger.desktop
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/ranger/ext/img_display.py

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
