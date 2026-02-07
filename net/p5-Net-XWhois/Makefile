PORTNAME=	Net-XWhois
PORTVERSION=	0.90
PORTREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Whois Client Interface for Perl5
WWW=		https://metacpan.org/release/Net-XWhois

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

.include <bsd.port.mk>
