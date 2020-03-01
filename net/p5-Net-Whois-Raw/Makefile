# Created by: Alex Kapranoff <kappa@FreeBSD.org.ua>
# $FreeBSD$

PORTNAME=	Net-Whois-Raw
PORTVERSION=	2.99027
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Very simple Perl interface to query raw whois data

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Net-IDN-Encode>=0:textproc/p5-Net-IDN-Encode \
		p5-Regexp-IPv6>=0:textproc/p5-Regexp-IPv6 \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Test-RequiresInternet>=0:devel/p5-Test-RequiresInternet

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
