# $FreeBSD$

PORTNAME=	Monitoring-Livestatus
PORTVERSION=	0.80
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NIERLEIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Perl API for check_mk livestatus

LICENSE=	GPLv1+
LICENSE_FILE=	${WRKSRC}/README

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cpanel-JSON-XS>=0:converters/p5-Cpanel-JSON-XS
TEST_DEPENDS=	p5-Test-More-UTF8>=0:devel/p5-Test-More-UTF8

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README
PORTEXAMPLES=	dump.pl test.pl

PLIST_FILES=	${SITE_PERL}/Monitoring/Livestatus.pm \
		${SITE_PERL}/Monitoring/Livestatus/INET.pm \
		${SITE_PERL}/Monitoring/Livestatus/UNIX.pm \
		${SITE_PERL}/man/man3/Monitoring::Livestatus.3.gz \
		${SITE_PERL}/man/man3/Monitoring::Livestatus::INET.3.gz \
		${SITE_PERL}/man/man3/Monitoring::Livestatus::UNIX.3.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
