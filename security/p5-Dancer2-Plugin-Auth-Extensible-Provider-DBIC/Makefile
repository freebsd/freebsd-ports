# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Auth-Extensible-Provider-DBIC
PORTVERSION=	0.600
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Extensible authentication framework for Dancer2 apps using DBIC

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Dancer2-Plugin-Auth-Extensible>=0.600:security/p5-Dancer2-Plugin-Auth-Extensible \
		p5-Dancer2-Plugin-DBIC>=0:databases/p5-Dancer2-Plugin-DBIC \
		p5-String-CamelCase>=0:textproc/p5-String-CamelCase
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
