# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Auth-Extensible-Provider-Database
PORTVERSION=	0.630
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible authentication for D2 apps using Dancer2-Plugin-Database

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer2-Plugin-Auth-Extensible>=0.600:security/p5-Dancer2-Plugin-Auth-Extensible \
		p5-Dancer2-Plugin-Database>=0.600:databases/p5-Dancer2-Plugin-Database

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
