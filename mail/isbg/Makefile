# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	isbg
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Scan an IMAP inbox for spam using SpamAssassin

# any OSI approved open source license
LICENSE=	BSD2CLAUSE

RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/spamassassin

USE_GITHUB=	yes
GH_ACCOUNT=	ook
GH_COMMIT=	44f46f0

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PLIST_FILES=	bin/${PORTNAME}.py

.include <bsd.port.mk>
