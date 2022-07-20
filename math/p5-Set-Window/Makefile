PORTNAME=	Set-Window
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manage an interval on the integer line

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' '/use 5/d' ${WRKSRC}/Window.pm

.include <bsd.port.mk>
