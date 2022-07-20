PORTNAME=	errbot
PORTVERSION=	6.1.9
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chatbot designed to be simple to extend with plugins

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansi>=0.2.0:devel/py-ansi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=6.6.0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemonize>=2.5.0:devel/py-daemonize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge>=1.0.1:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.19.16:devel/dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=2.0.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.6:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.9.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=21.0.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=2.0.32:www/py-WebTest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	IRC SLACK_RTM TELEGRAM XMPP
IRC_DESC=	IRC messaging support
SLACK-RTM_DESC=	Slack messaging support
TELEGRAM_DESC=	Telegram messaging support
XMPP_DESC=	XMPP messaging support

IRC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}irc>=20.0.0:irc/py-irc@${PY_FLAVOR}
SLACK-RTM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slackclient>=2.9.3:net-im/py-slackclient@${PY_FLAVOR}
TELEGRAM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-telegram-bot>=13.10:net-im/py-python-telegram-bot@${PY_FLAVOR}
XMPP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.4.8:devel/py-pyasn1@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.8:devel/py-pyasn1-modules@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}slixmpp>=1.7.1:net-im/py-slixmpp@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}graphlib-backport>=1.0.3:graphics/py-graphlib-backport@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
