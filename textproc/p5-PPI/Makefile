# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PPI
PORTVERSION=	1.224
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MITHALDU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Analyze and manipulate Perl code without using perl itself

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Inspector>=1.22:devel/p5-Class-Inspector \
		p5-Clone>=0.30:devel/p5-Clone \
		p5-File-Remove>=1.42:devel/p5-File-Remove \
		p5-IO-String>=1.07:devel/p5-IO-String \
		p5-List-MoreUtils>=0.16:lang/p5-List-MoreUtils \
		p5-Params-Util>=1.00:devel/p5-Params-Util \
		p5-Task-Weaken>0:devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Object>=0.07:devel/p5-Test-Object \
		p5-Test-SubCalls>=1.07:devel/p5-Test-SubCalls \
		p5-Test-Warn>=0.30:devel/p5-Test-Warn

PORTSCOUT=	limit:^[0-9\.]*$$

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
