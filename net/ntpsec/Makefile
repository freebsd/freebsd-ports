# $FreeBSD$

PORTNAME=	ntpsec
DISTVERSIONPREFIX=	NTPsec_
DISTVERSION=	1_1_9-57
DISTVERSIONSUFFIX=	-ge91d6e5c2
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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000 && ${SSL_DEFAULT} == base
BROKEN=		Needs OpenSSL with TLSv1.3 support but OpenSSL in base on FreeBSD 11 doesn't support TLSv1.3
.endif

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l | ${SED} -e 's|^share/man/.*|&.gz|' >> ${TMPPLIST}

.include <bsd.port.mk>
