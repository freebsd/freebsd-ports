PORTNAME=	HTML-Table
PORTVERSION=	2.08a
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate HTML tables for CGI scripts

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	skipv:2.08

post-extract:
	@${REINPLACE_CMD} -e 's|2.08a|2.08_1|' ${WRKSRC}/lib/HTML/Table.pm
	${RM} ${WRKSRC}/lib/HTML/Table.pm.bak

.include <bsd.port.mk>
