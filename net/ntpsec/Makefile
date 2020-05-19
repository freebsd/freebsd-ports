# $FreeBSD$

PORTNAME=	ntpsec
DISTVERSIONPREFIX=	NTPsec_
DISTVERSION=	1_1_8
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network Time Protocol suite, refactored

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc
LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

USES=		bison gettext-runtime pkgconfig python shebangfix ssl waf
SHEBANG_FILES=	${WRKSRC}/ntpclients/ntp*.py
USE_GITHUB=	yes

CONFLICTS=	ntp ntp-devel openntpd

MAKE_ENV=	NOSYNC=1 # workaround for the console problem: https://gitlab.com/NTPsec/ntpsec/issues/599

PORTSCOUT=	limit:^\d+\. # prevent alpha-numeric strings

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l | ${SED} -e 's|^share/man/.*|&.gz|' >> ${TMPPLIST}

.include <bsd.port.mk>
