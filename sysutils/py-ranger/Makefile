# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	ranger
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	http://ranger.nongnu.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	linpct@gmail.com
COMMENT=	Ranger is a file manager with VI key bindings

USES=		python
USE_PYTHON=	distutils

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|; s|share/man/man|man/man|;s|share/doc|doc|' ${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/ranger/ext/img_display.py

.include <bsd.port.mk>
