PORTNAME=	Date-Handler
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for calculating time differences

USES=		perl5
USE_PERL5=	configure patch
NO_ARCH=	yes

post-patch:
	@${PERL} -pi -e 's/[a-z][a-z]_[A-Z][A-Z]/$$&.ISO8859-15/g' \
		${WRKSRC}/Handler.* ${WRKSRC}/README*

.include <bsd.port.mk>
