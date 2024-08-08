PORTNAME=	alpaca
DISTVERSION=	1.0.6
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Ollama client made with GTK4 and Adwaita
WWW=		https://github.com/Jeffser/Alpaca

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtksourceview-5.so:x11-toolkits/gtksourceview5
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}gobject3>=3.42.2:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=2.2.3:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>=4.3.1:print/py-pypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytube>=15.0.0:multimedia/py-pytube@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		ollama:misc/ollama

USES=		meson python
USE_GITHUB=	yes
GH_ACCOUNT=	Jeffser
GH_PROJECT=	Alpaca

post-patch:
	@${REINPLACE_CMD} \
		-e 's/python3/${PYTHON_VERSION}/1' ${WRKSRC}/src/meson.build

.include <bsd.port.mk>
