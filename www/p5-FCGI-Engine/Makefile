# Created by: Anes Muhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	FCGI-Engine
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible engine for running FCGI-based applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Simple>=0:www/p5-CGI-Simple \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-Declare-Constraints-Simple>=0:devel/p5-Declare-Constraints-Simple \
		p5-FCGI>=0:www/p5-FCGI \
		p5-Moose>=0.93:devel/p5-Moose \
		p5-MooseX-Daemonize>=0.09:devel/p5-MooseX-Daemonize \
		p5-MooseX-Getopt>=0.26:devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize>=0:devel/p5-Test-WWW-Mechanize

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
