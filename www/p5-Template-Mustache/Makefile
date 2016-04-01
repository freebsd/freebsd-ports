# Created by: Kurt Lidl <kurt.lidl@cello.com>
# $FreeBSD$

PORTNAME=	Template-Mustache
PORTVERSION=	v0.5.1
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Perl version of the fabulous Mustache template language

BUILD_DEPENDS=	p5-YAML-Syck>=1.15:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS:=	p5-Test-Mini-Unit>=v1.0.3:devel/p5-Test-Mini-Unit

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
