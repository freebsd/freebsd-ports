PORTNAME=	RDR-Collector
PORTVERSION=	1.0000
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN/RDR
PKGNAMEPREFIX=	p5-

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Perl5 module to capture and process raw Cisco SCE RDRv1 packets

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	examples/*.pl

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
