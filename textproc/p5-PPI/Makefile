# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PPI
PORTVERSION=	1.220
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MITHALDU
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Analyze and manipulate Perl code without using perl itself

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	\
		p5-Clone>=0.30:devel/p5-Clone \
		p5-IO-String>=1.07:devel/p5-IO-String \
		p5-List-MoreUtils>=0.16:lang/p5-List-MoreUtils \
		p5-Params-Util>=1.00:devel/p5-Params-Util \
		p5-Task-Weaken>0:devel/p5-Task-Weaken \
		p5-Class-Inspector>=1.22:devel/p5-Class-Inspector \
		p5-File-Remove>=1.42:devel/p5-File-Remove
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0.084:devel/p5-Test-NoWarnings \
		p5-Test-Object>=0.07:devel/p5-Test-Object \
		p5-Test-SubCalls>=1.07:devel/p5-Test-SubCalls

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
