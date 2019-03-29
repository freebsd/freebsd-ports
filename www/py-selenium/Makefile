# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	selenium
PORTVERSION=	3.141.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python bindings for Selenium

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR}

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
