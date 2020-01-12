# $FreeBSD$

PORTNAME=	ntpsec
DISTVERSIONPREFIX=	NTPsec_
DISTVERSION=	1_1_8
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network Time Protocol suite, refactored

LICENSE=	BSD3CLAUSE

USES=		bison gettext-runtime pkgconfig python shebangfix ssl waf
SHEBANG_FILES=	${WRKSRC}/ntpclients/ntp*.py
USE_GITHUB=	yes

MAKE_ENV=	NOSYNC=1 # workaround for the console problem: https://gitlab.com/NTPsec/ntpsec/issues/599

PORTSCOUT=	limit:^[0-9_\.]*$$

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l | ${SED} -e 's|^man/.*|&.gz|' >> ${TMPPLIST}

.include <bsd.port.mk>
