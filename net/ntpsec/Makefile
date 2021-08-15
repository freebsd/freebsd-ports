PORTNAME=	ntpsec
DISTVERSIONPREFIX=	NTPsec_
DISTVERSION=	1_2_0
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network Time Protocol suite, refactored

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

USES=		cpe bison gettext-runtime pkgconfig python shebangfix ssl waf
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/lib/ntp

SHEBANG_FILES=	${WRKSRC}/ntpclients/ntp*.py
python_OLD_CMD=	@PYSHEBANG@

CONFLICTS=	ntp ntp-devel openntpd

MAKE_ENV=	NOSYNC=1 # workaround for the console problem: https://gitlab.com/NTPsec/ntpsec/issues/599

OPTIONS_DEFINE=			DOCS

DOCS_CONFIGURE_ENABLE=	doc
DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor # alternatively ntpsec can use asciidoc:textproc/asciidoc but it prefers asciidoctor

PORTSCOUT=	limit:^\d+\. # prevent alpha-numeric strings

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000 && ${SSL_DEFAULT} == base
BROKEN=		Needs OpenSSL with TLSv1.3 support but OpenSSL in base on FreeBSD 11 doesn't support TLSv1.3
.endif

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l | ${SED} -e 's|^share/man/.*|&.gz|' >> ${TMPPLIST}

.include <bsd.port.mk>
