# New ports collection makefile for:	p5-Apache
# Date created:				April 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Apache
PORTVERSION=	1.24
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
DISTNAME=	mod_perl-${PORTVERSION}

MAINTAINER=	jfitz@FreeBSD.org

.if !defined(APACHE_PORT)
APACHE_PORT=apache13
.endif
BUILD_DEPENDS=	${PREFIX}/sbin/apxs:${PORTSDIR}/www/${APACHE_PORT} \
		${PREFIX}/bin/lwp-download:${PORTSDIR}/www/p5-libwww

USE_PERL5=	YES
MAN3=		Apache.3 \
		Apache::Constants.3 \
		Apache::Debug.3 \
		Apache::ExtUtils.3 \
		Apache::FakeRequest.3 \
		Apache::File.3 \
		Apache::Include.3 \
		Apache::Leak.3 \
		Apache::Log.3 \
		Apache::Options.3 \
		Apache::PerlRun.3 \
		Apache::PerlRunXS.3 \
		Apache::PerlSections.3 \
		Apache::RedirectLogFix.3 \
		Apache::Registry.3 \
		Apache::RegistryLoader.3 \
		Apache::Resource.3 \
		Apache::SIG.3 \
		Apache::SizeLimit.3 \
		Apache::StatINC.3 \
		Apache::Status.3 \
		Apache::Symbol.3 \
		Apache::Symdump.3 \
		Apache::Table.3 \
		Apache::URI.3 \
		Apache::Util.3 \
		Apache::httpd_conf.3 \
		Apache::src.3 \
		Bundle::Apache.3 \
		cgi_to_mod_perl.3 \
		mod_perl.3 \
		mod_perl_cvs.3 \
		mod_perl_method_handlers.3 \
		mod_perl_traps.3 \
		mod_perl_tuning.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL USE_APXS=1 WITH_APXS=${PREFIX}/sbin/apxs EVERYTHING=1

post-install:
		${MKDIR} ${PREFIX}/include/apache/modules/perl
		${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
		    ${PREFIX}/include/apache/modules/perl
		${MKDIR} ${PREFIX}/share/doc/mod_perl
		${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/mod_perl
.if !defined(BATCH)
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
