# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	pywikibot
DISTVERSION=	6.3.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wikipedia bot for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.20.1:www/py-requests@${PY_FLAVOR}

USES=		dos2unix python:3.5+
DOS2UNIX_FILES=	setup.py
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	EVENTSTREAMS ISBN PYDOT GOOGLE IRC MWPARSE PILLOW MWOAUTH HTML
EVENTSTREAMS_DESC=		Support for reading Server Sent Event streams
ISBN_DESC=			Support for standard numbers and codes via stdnum package
PYDOT_DESC=			Support for Graphviz via pydot module
GOOGLE_DESC=			Support for Google search
IRC_DESC=			Support for IRC
MWPARSE_DESC=			Support for MediaWiki parser
PILLOW_DESC=			Support for image processing via pillow module
MWOAUTH_DESC=			Support for MediaWiki OAuth handshake helper
HTML_DESC=			Support for HTML/XML Parser for Python

EVENTSTREAMS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sseclient>0:www/py-sseclient@${PY_FLAVOR}
ISBN_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}stdnum>0:devel/py-stdnum@${PY_FLAVOR}
PYDOT_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pydot>0:graphics/py-pydot@${PY_FLAVOR}
GOOGLE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}google>0:www/py-google@${PY_FLAVOR}
IRC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}irc>0:irc/py-irc@${PY_FLAVOR}
MWPARSE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}mwparserfromhell>0:textproc/py-mwparserfromhell@${PY_FLAVOR}
PILLOW_RUN_DEPENDS=		${PY_PILLOW}
MWOAUTH_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}mwoauth>0:www/py-mwoauth@${PY_FLAVOR}
HTML_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

.include <bsd.port.mk>
