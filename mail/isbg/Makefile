# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	isbg
PORTVERSION=	2.2.1
CATEGORIES=	mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scan an IMAP inbox for spam using SpamAssassin

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.6.1:devel/py-docopt@${PY_FLAVOR} \
		spamassassin:mail/spamassassin

USES=		python

USE_GITLAB=	yes
GL_ACCOUNT=	isbg
GL_COMMIT=	e626d8d0628f691c041032c53f20d764b11d0079

NO_ARCH=	yes
NO_BUILD=	yes
USE_PYTHON=	autoplist concurrent distutils optsuffix

.include <bsd.port.mk>
