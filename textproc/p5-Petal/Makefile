# New ports collection makefile for:	p5-Petal
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Petal
PORTVERSION=	2.19
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/B/BP/BPOSTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl Template Attribute Language - TAL for Perl!

BUILD_DEPENDS=	${SITE_PERL}/MKDoc/XML.pm:${PORTSDIR}/textproc/p5-MKDoc-XML \
		${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Petal.3 \
	Petal::Cookbook.3 \
	Petal::Deprecated.3 \
	Petal::Hash::Test.3 \
	Petal::I18N.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
