# New ports collection makefile for:	mod_perl2
# Date created:				February 13th 2003
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	mod_perl
PORTVERSION=	1.99r17
CATEGORIES=	www perl5
MASTER_SITES=	http://perl.apache.org/dist/ \
		http://perl.apache.org/dist/old/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/_/}

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Embeds a Perl interpreter in the Apache2 server

USE_APACHE=	yes
WITH_APACHE2=	yes
PERL_CONFIGURE=	yes

CONFIGURE_ARGS=	MP_APXS=${LOCALBASE}/sbin/apxs \
		MP_INST_APACHE2=1 PREFIX=${PREFIX}

MAN3=		Apache::Build.3 Apache::Test.3 Apache::TestConfig.3 \
		Apache::TestMB.3 Apache::TestMM.3 Apache::TestReport.3 \
		Apache::TestRequest.3 Apache::TestRun.3 \
		Apache::TestRunPerl.3 Apache::TestSmoke.3 \
		Apache::TestTrace.3 Apache::TestUtil.3 Bundle::Apache2.3 \
		Bundle::ApacheTest.3 ModPerl::CScan.3 ModPerl::Code.3 \
		ModPerl::Config.3 mod_perl.3

.include <bsd.port.pre.mk>

# it is time to require perl 5.8.x
.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

# no idea why r16 and r17 require this - the perl build should do this copy
pre-install:
	${CP} ${WRKSRC}/WrapXS/APR/ThreadMutex/ThreadMutex.pm \
		${WRKSRC}/blib/lib/Apache2/APR/

post-install:
	${MKDIR} ${PREFIX}/include/apache2/modules/perl
	${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
		${PREFIX}/include/apache2/modules/perl
	${MKDIR} ${PREFIX}/libexec/apache2
	${INSTALL_PROGRAM} ${WRKSRC}/src/modules/perl/mod_perl.so \
		${PREFIX}/libexec/apache2/mod_perl.so
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
