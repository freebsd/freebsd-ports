PORTNAME=	selenium
PORTVERSION=	4.12.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python bindings for Selenium
WWW=		https://www.seleniumhq.org/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.26:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.17:net/py-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio-websocket>=0.9:net/py-trio-websocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2021.10.8:security/py-certifi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	FIREFOX CHROMIUM
FIREFOX_DESC=	Install Firefox and geckodriver
CHROMIUM_DESC=	Install Chromium

FIREFOX_RUN_DEPENDS=	firefox:www/firefox geckodriver:www/geckodriver
CHROMIUM_RUN_DEPENDS=	chromedriver:www/chromium

# Don't install binary Firefox extension
post-extract:
	@${RM} ${WRKSRC}/selenium/webdriver/firefox/amd64/x_ignore_nofocus.so
	@${RM} ${WRKSRC}/selenium/webdriver/firefox/x86/x_ignore_nofocus.so

.include <bsd.port.mk>
