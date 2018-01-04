# Created by: Greg Fitzgerald <gregf@hugops.pw>
# $FreeBSD$

PORTNAME=	fb
PORTVERSION=	2.0.3
CATEGORIES=	net python
MASTER_SITES=	http://paste.xinu.at/data/client/

MAINTAINER=	gregf@hugops.pw
COMMENT=	Client for paste.xinu.at

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyliblzma>0:archivers/py-pyliblzma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

USES=	python:2.7 shebangfix
NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/fb

PLIST_FILES=	bin/fb man/man1/fb.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|PREFIX=/usr|PREFIX=${LOCALBASE}|g ; \
		 s|share/man|man|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
