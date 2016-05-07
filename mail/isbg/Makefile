# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	isbg
PORTVERSION=	1.00
CATEGORIES=	mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scan an IMAP inbox for spam using SpamAssassin

# any OSI approved open source license
LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	spamassassin:mail/spamassassin \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6.1:devel/py-docopt

USE_GITHUB=	yes

NO_ARCH=	yes
NO_BUILD=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
