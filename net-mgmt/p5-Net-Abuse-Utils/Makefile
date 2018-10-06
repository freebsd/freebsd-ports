# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Abuse-Utils
PORTVERSION=	0.27
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Routines useful for processing network abuse

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Address-XS>=0:mail/p5-Email-Address-XS \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-Net-Whois-IP>=1.11:net/p5-Net-Whois-IP

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/ip-info.pl ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
