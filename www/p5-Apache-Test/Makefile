# New ports collection makefile for:	Apache-Test
# Date created:	   05 July 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-Test
PORTVERSION=	1.21
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Test.pm wrapper with helpers for testing Apache

.if defined(WITH_MODPERL2)
IGNORE=		"This port is already included in mod_perl2"
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS}
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::Test.3 Apache::TestConfig.3 Apache::TestConfigData.3 \
		Apache::TestMB.3 Apache::TestMM.3 Apache::TestReport.3 \
		Apache::TestRequest.3 Apache::TestRun.3 Apache::TestRunPHP.3 \
		Apache::TestRunPerl.3 Apache::TestSmoke.3 Apache::TestTrace.3 \
		Apache::TestUtil.3 Bundle::ApacheTest.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.if ${PERL_LEVEL} < 500800
EXTRA_PATCHES=	${PATCHDIR}/500503-Makefile.PL
.endif

post-patch:
	@${PERL} -pi.bak -e 's/^/#/ if $$.==26;' ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e '$$_="" if $$.==11;' ${WRKSRC}/lib/Apache/Test5005compat.pm
.if ${PERL_LEVEL} < 500800
	@${PERL} -pi.bak -e 's/PERLRUN/PERL/;' ${WRKSRC}/install-pl
.endif
.if ${PERL_LEVEL} < 500600
	@${PERL} -pi -e 's/\b(?:use|no) warnings[^;]*;//g' \
	${WRKSRC}/lib/Apache/*.pm ${WRKSRC}/Makefile.PL ${WRKSRC}/install-pl
.endif

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
