# Created by: Andrej Zverev <andrey.zverev@electro-com.ru>
# $FreeBSD$

PORTNAME=	HTML-FormFu
PORTVERSION=	0.09010
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML Form Creation, Rendering and Validation Framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Captcha-reCAPTCHA>=0.93:${PORTSDIR}/graphics/p5-Captcha-reCAPTCHA \
		p5-Class-Accessor-Chained>=0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Clone>=0.31:${PORTSDIR}/devel/p5-Clone \
		p5-Config-Any>=0.18:${PORTSDIR}/devel/p5-Config-Any \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES \
		p5-Data-Visitor>=0.26:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-DateTime>=0.54:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.79:${PORTSDIR}/devel/p5-DateTime-Format-Builder \
		p5-DateTime-Format-Natural>=0:${PORTSDIR}/devel/p5-DateTime-Format-Natural \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime-Locale>=0.45:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-HTML-TokeParser-Simple>=3.14:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-Hash-Flatten>=0:${PORTSDIR}/devel/p5-Hash-Flatten \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Aliases>=0:${PORTSDIR}/devel/p5-MooseX-Aliases \
		p5-MooseX-Attribute-Chained>=1.0.1:${PORTSDIR}/devel/p5-MooseX-Attribute-Chained \
		p5-MooseX-SetOnce>=0:${PORTSDIR}/devel/p5-MooseX-SetOnce \
		p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-YAML-LibYAML>=0.32:${PORTSDIR}/textproc/p5-YAML-LibYAML \
		p5-libwww>=1.64:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CGI-Simple>=0:${PORTSDIR}/www/p5-CGI-Simple \
		p5-Test-Aggregate>=0:${PORTSDIR}/devel/p5-Test-Aggregate \
		p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
