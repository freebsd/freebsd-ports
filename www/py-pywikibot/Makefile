# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pywikibot
DISTVERSION=	3.0.20180304
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wikipedia bot for Python

LICENSE=	MIT

RUN_DEPENDS=	${PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
DOS2UNIX_FILES=	setup.py

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

EVENTSTREAMS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sseclient>0:www/py-sseclient@${FLAVOR}
ISBN_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}stdnum>0:devel/py-stdnum@${FLAVOR}
PYDOT_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pydot>0:graphics/py-pydot@${FLAVOR}
GOOGLE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}google>0:www/py-google@${FLAVOR}
IRC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}irc>0:irc/py-irc@${FLAVOR}
MWPARSE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}mwparserfromhell>0:textproc/py-mwparserfromhell@${FLAVOR}
PILLOW_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR}
MWOAUTH_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}mwoauth>0:www/py-mwoauth@${FLAVOR}
HTML_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddr>0:devel/py-ipaddr@${FLAVOR}
.endif

.include <bsd.port.post.mk>
