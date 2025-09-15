PORTNAME=	itstool
PORTVERSION=	2.0.7
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	https://files.itstool.org/itstool/

PATCH_SITES=	https://github.com/itstool/itstool/commit/
PATCHFILES=	32c7d07664dc37765100285d1202d488cd6a27e8.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Translate XML with PO files using W3C Internationalization Tag Set rules
WWW=		https://itstool.org/ \
		https://github.com/itstool/itstool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		autoreconf python tar:bzip2

GNU_CONFIGURE=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|g' ${WRKSRC}/itstool.in

.include <bsd.port.mk>
