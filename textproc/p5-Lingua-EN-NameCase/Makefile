# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Lingua-EN-NameCase
PORTVERSION=	1.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to fix the case of people's names

LICENSE=	ART20

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|Lingua-EN-NameCase|Lingua::EN::NameCase|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
