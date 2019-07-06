# $FreeBSD$

PORTNAME=	ntpsec
DISTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network Time Protocol suite, refactored

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison gettext-runtime python shebangfix ssl waf
SHEBANG_FILES=	${WRKSRC}/ntpclients/ntp*.py
USE_GITLAB=	yes
GL_ACCOUNT=	NTPsec
GL_COMMIT=	79cd18fc56fc902c3a7fd78bcc32ee72f52eb396

MAKE_ENV=	NOSYNC=1 # workaround for the console problem: https://gitlab.com/NTPsec/ntpsec/issues/599

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
