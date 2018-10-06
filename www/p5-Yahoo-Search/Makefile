# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Yahoo-Search
PORTVERSION=	1.11.3
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Yahoo Search public API

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI>=1.54:net/p5-URI \
		p5-libwww>=5.835:www/p5-libwww
TEST_DEPENDS=	p5-Test-Simple>=0.88:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
