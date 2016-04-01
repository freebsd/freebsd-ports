# $FreeBSD$

PORTNAME=	Catalyst-Model-CDBI-Plain
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Catalyst plain base class for Class::DBI models

BUILD_DEPENDS=	p5-Class-DBI>0:databases/p5-Class-DBI \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>0:www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>0:www/p5-Catalyst-Devel

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
