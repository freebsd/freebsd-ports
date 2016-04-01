# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-Auth-Extensible-Provider-Usergroup
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Extensible authentication framework for Dancer apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.3118:www/p5-Dancer \
		p5-Dancer-Plugin-Auth-Extensible>=0:security/p5-Dancer-Plugin-Auth-Extensible \
		p5-Dancer-Plugin-Passphrase>=0:security/p5-Dancer-Plugin-Passphrase \
		p5-Dancer-Plugin-DBIC>=0:databases/p5-Dancer-Plugin-DBIC
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
