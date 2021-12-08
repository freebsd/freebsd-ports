PORTNAME=	ntpsec
DISTVERSIONPREFIX=	NTPsec_
DISTVERSION=	1_2_1
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

TEST_TARGET=	check

OPTIONS_DEFINE=			DOCS

DOCS_CONFIGURE_ENABLE=	doc
DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor # alternatively ntpsec can use asciidoc:textproc/asciidoc but it prefers asciidoctor

PORTSCOUT=	limit:^\d+\. # prevent alpha-numeric strings

post-install: # autoplist: plist varies depending on the python version
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l | ${SED} -e 's|^share/man/.*|&.gz|' >> ${TMPPLIST}

.include <bsd.port.mk>
