# Created by: gugu
# $FreeBSD$

PORTNAME=	HTML-FormHandler
PORTVERSION=	0.40065
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Form handler written in Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Load>=0.06:devel/p5-Class-Load \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-Data-Clone>=0:devel/p5-Data-Clone \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Email-Valid>=0:mail/p5-Email-Valid \
		p5-File-ShareDir-Install>=0.3:devel/p5-File-ShareDir-Install \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-JSON>=0:converters/p5-JSON \
		p5-Locale-Maketext>=1.09:devel/p5-Locale-Maketext \
		p5-Moose>=2.1403:devel/p5-Moose \
		p5-MooseX-Getopt>=0.16:devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Common>=0:devel/p5-MooseX-Types-Common \
		p5-MooseX-Types-LoadableClass>=0.006:devel/p5-MooseX-Types-LoadableClass \
		p5-MooseX-Types>=0.20:devel/p5-MooseX-Types \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-aliased>=0:devel/p5-aliased \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
