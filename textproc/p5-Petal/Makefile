# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Petal
PORTVERSION=	2.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NINE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Template Attribute Language - TAL for Perl!

BUILD_DEPENDS=	p5-MKDoc-XML>=0:${PORTSDIR}/textproc/p5-MKDoc-XML
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Petal.3 \
	Petal::Cookbook.3 \
	Petal::Deprecated.3 \
	Petal::Hash::Test.3 \
	Petal::I18N.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
