# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Auth-Extensible
PORTVERSION=	0.708
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible authentication framework for Dancer2 apps

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-SaltedHash>=0:security/p5-Crypt-SaltedHash \
		p5-Dancer2>=0.204000:www/p5-Dancer2 \
		p5-File-Share>=0:devel/p5-File-Share \
		p5-HTTP-BrowserDetect>=0:www/p5-HTTP-BrowserDetect \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.000000:devel/p5-Moo \
		p5-Plack>=1.0029:www/p5-Plack \
		p5-Session-Token>=0:security/p5-Session-Token \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-YAML>=0:textproc/p5-YAML \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Path-Tiny>=0.016:devel/p5-Path-Tiny \
		p5-Test-Deep>=0.114:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockDateTime>=0:devel/p5-Test-MockDateTime \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	DPAEPU
DPAEPU_DESC=	Extra dependencies for Provider::Unix

DPAEPU_BUILD_DEPENDS=	p5-Authen-Simple-PAM>=0:security/p5-Authen-Simple-PAM

.include <bsd.port.mk>
