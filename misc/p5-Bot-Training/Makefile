# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Bot-Training
PORTVERSION=	0.06
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FIBO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Plain text training material for bots like Hailo and MegaHAL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Dir-Self>=0:devel/p5-Dir-Self \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Moose>=0.82:devel/p5-Moose \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-namespace-clean>=0:devel/p5-namespace-clean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
