# New ports collection makefile for:	mod_perl2
# Date created:				February 13th 2003
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	mod_perl
PORTVERSION=	1.99r10
CATEGORIES=	www perl5
MASTER_SITES=	http://perl.apache.org/dist/ \
		http://perl.apache.org/dist/old/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/_/}

MAINTAINER=	larse@isi.edu
COMMENT=	Embeds a Perl interpreter in the Apache2 server

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${APACHE2_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${APACHE2_PORT}

USE_PERL5=	YES

INSTALLS_SHLIB=	YES
LDCONFIG_DIRS=	%%PREFIX%%/libexec/apache2/

MAN3=		Apache::TestRequest.3 Apache::TestSmoke.3 Apache::TestRun.3 \
		Apache::TestTrace.3 Apache::TestMM.3 Bundle::ApacheTest.3 \
		Apache::Test.3 Apache::TestUtil.3 Apache::Build.3 \
		Bundle::Apache2.3 ModPerl::Code.3

APACHE2_PORT?=	${PORTSDIR}/www/apache2

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} > 500601
MAN3+=		ModPerl::Config.3 Apache::TestConfig.3
.endif

##
## this port requires PERL 5.6.x or later
##
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

do-configure:
	@ cd ${WRKSRC}; \
	${PERL5} Makefile.PL MP_APXS=${LOCALBASE}/sbin/apxs \
		MP_INST_APACHE2=1 PREFIX=${PREFIX}

post-install:
	${MKDIR} ${PREFIX}/include/apache2/modules/perl
	${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
		${PREFIX}/include/apache2/modules/perl
	${MKDIR} ${PREFIX}/libexec/apache2
	${INSTALL_PROGRAM} ${WRKSRC}/src/modules/perl/mod_perl.so \
		${PREFIX}/libexec/apache2/mod_perl.so

.include <bsd.port.post.mk>
