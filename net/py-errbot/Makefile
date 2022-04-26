# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	errbot
PORTVERSION=	6.1.8
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chatbot designed to be simple to extend with plugins

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansi>=0:devel/py-ansi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemonize>=0:devel/py-daemonize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge>=0.1.0:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.19.16:devel/dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=0:www/py-WebTest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	IRC SLACK_RTM TELEGRAM XMPP
IRC_DESC=	IRC messaging support
SLACK-RTM_DESC=	Slack messaging support
TELEGRAM_DESC=	Telegram messaging support
XMPP_DESC=	XMPP messaging support

IRC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}irc>=0:irc/py-irc@${PY_FLAVOR}
SLACK-RTM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slackclient>=2.0:net-im/py-slackclient@${PY_FLAVOR}
TELEGRAM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-telegram-bot>=0:net-im/py-python-telegram-bot@${PY_FLAVOR}
XMPP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0:devel/py-pyasn1-modules@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}slixmpp>=0:net-im/py-slixmpp@${PY_FLAVOR}

.include <bsd.port.mk>
