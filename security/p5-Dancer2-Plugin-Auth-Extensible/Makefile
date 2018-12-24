# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Auth-Extensible
PORTVERSION=	0.706
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible authentication framework for Dancer2 apps

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SaltedHash>0:security/p5-Crypt-SaltedHash \
		p5-Session-Token>0:security/p5-Session-Token \
		p5-File-ShareDir-Install>0:devel/p5-File-ShareDir-Install \
		p5-Dancer2>=0.204001:www/p5-Dancer2
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-File-Share>0:devel/p5-File-Share
TEST_DEPENDS=	p5-HTTP-Cookies>0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-Plack>0:www/p5-Plack \
		p5-Test-Deep>=0.114:devel/p5-Test-Deep \
		p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-MockDateTime>0:devel/p5-Test-MockDateTime \
		p5-Test-Warnings>0:devel/p5-Test-Warnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DPAEPU
DPAEPU_DESC=	Extra dependencies for Provider::Unix

DPAEPU_BUILD_DEPENDS=	p5-Authen-Simple-PAM>=0:security/p5-Authen-Simple-PAM

.include <bsd.port.mk>
