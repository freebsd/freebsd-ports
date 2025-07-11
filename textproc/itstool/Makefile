PORTNAME=	itstool
PORTVERSION=	2.0.7
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://files.itstool.org/itstool/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Translate XML with PO files using W3C Internationalization Tag Set rules
WWW=		https://itstool.org/ \
		https://github.com/itstool/itstool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2-python>=0:textproc/libxml2-python@${PY_FLAVOR}

USES=		python tar:bzip2

GNU_CONFIGURE=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|g' ${WRKSRC}/itstool.in

.include <bsd.port.mk>
