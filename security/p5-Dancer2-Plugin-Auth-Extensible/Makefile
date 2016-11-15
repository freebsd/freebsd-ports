# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Auth-Extensible
PORTVERSION=	0.622
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Extensible authentication framework for Dancer2 apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SaltedHash>=0:security/p5-Crypt-SaltedHash \
		p5-Session-Token>=0:security/p5-Session-Token \
		p5-Dancer2>=0.204001:www/p5-Dancer2
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DPAEPU
DPAEPU_DESC=	Extra dependencies for Provider::Unix

DPAEPU_BUILD_DEPENDS=	p5-Authen-Simple-PAM>=0:security/p5-Authen-Simple-PAM

.include <bsd.port.mk>
