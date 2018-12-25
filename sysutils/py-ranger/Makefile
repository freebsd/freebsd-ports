# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	ranger
PORTVERSION=	1.9.2
CATEGORIES=	sysutils python
MASTER_SITES=	https://ranger.github.io/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	linpct@gmail.com
COMMENT=	Ranger is a file manager with VI key bindings

LICENSE=	GPLv3

USES=		python shebangfix
SHEBANG_FILES=	doc/tools/*.py
python_OLD_CMD=	/bin/python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|; s|share/man/man|man/man|;s|share/doc|doc|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/ranger/ext/img_display.py

.include <bsd.port.mk>
