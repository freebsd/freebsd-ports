# $FreeBSD$

PORTNAME=	ntpsec
DISTVERSION=	1.1.4
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network Time Protocol suite, refactored

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison gettext-runtime python:2.7 shebangfix ssl waf # python-3.6 has 2 issues: plist differences, and terminal-related failure: https://gitlab.com/NTPsec/ntpsec/issues/599
SHEBANG_FILES=	${WRKSRC}/ntpclients/ntp*.py
USE_GITLAB=	yes
GL_ACCOUNT=	NTPsec
GL_COMMIT=	79cd18fc56fc902c3a7fd78bcc32ee72f52eb396

.include <bsd.port.mk>
