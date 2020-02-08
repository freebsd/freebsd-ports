# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Simple
PORTVERSION=	1.240
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|0$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple totally OO CGI interface that is CGI.pm compliant

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
