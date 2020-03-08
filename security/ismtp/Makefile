# $FreeBSD$

PORTNAME=	ismtp
DISTVERSION=	g20180824
CATEGORIES=	security
MASTER_SITES=	GH

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Test for SMTP user enumeration,internal spoofing, and relay

LICENSE=	MIT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	altjx
GH_PROJECT=	ipwn
GH_TAGNAME=	32bbc05
GH_SUBDIR=	iSMTP

NO_BUILD=	yes

SHEBANG_FILES=	${WRKSRC}/${GH_SUBDIR}/iSMTP.py

PLIST_FILES=	bin/ismtp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/iSMTP.py  ${STAGEDIR}${PREFIX}/bin/ismtp

.include <bsd.port.mk>
