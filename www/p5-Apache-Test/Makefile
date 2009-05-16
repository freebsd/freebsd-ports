# New ports collection makefile for:	Apache-Test
# Date created:	   05 July 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-Test
PORTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Test.pm wrapper with helpers for testing Apache

MAKE_JOBS_SAFE=  yes

## XXX: Need to fix this, www/mod_perl2 currently @2.0.3 contains A-T 1.29,
## XXX: but
## XXX: A-T has released 1.30
.if defined(WITH_MODPERL2)
IGNORE=		is already included in mod_perl2
.endif

USE_APACHE=1.3+

PERL_CONFIGURE=	yes

MAN3=		Apache::Test.3 Apache::TestConfig.3 Apache::TestConfigData.3 \
		Apache::TestMB.3 Apache::TestMM.3 Apache::TestReport.3 \
		Apache::TestRequest.3 Apache::TestRun.3 Apache::TestRunPHP.3 \
		Apache::TestRunPerl.3 Apache::TestServer.3 \
		Apache::TestSmoke.3 Apache::TestTrace.3 \
		Apache::TestUtil.3 Bundle::ApacheTest.3

.include <bsd.port.mk>
