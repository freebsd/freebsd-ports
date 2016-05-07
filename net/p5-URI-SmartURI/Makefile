# Created by: Oleg Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	URI-SmartURI
PORTVERSION=	0.032
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Subclassable and hostless URIs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-C3-Componentised>=0:devel/p5-Class-C3-Componentised \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0.09:devel/p5-MRO-Compat \
		p5-Moose>=0:devel/p5-Moose \
		p5-URI>=1.51:net/p5-URI \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>0:devel/p5-Test-Fatal \
		p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
