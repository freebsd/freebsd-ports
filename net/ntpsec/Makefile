# $FreeBSD$

PORTNAME=	ntpsec
DISTVERSION=	1.1.6
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
GL_COMMIT=	0d119a8faf80180ac144e3c1f21988cfd708ed91

MAKE_ENV=	NOSYNC=1 # workaround for the console problem: https://gitlab.com/NTPsec/ntpsec/issues/599

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
