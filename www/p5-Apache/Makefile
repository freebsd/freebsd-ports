# New ports collection makefile for:	p5-Apache
# Version required:			1.19
# Date created:				April 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mod_perl-1.19
PKGNAME=	p5-Apache-1.19
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/www/apache13:patch

USE_PERL5=	YES
CONFIGURE_ENV=	APACHEDIR=${WRKDIRPREFIX}${.CURDIR}/../apache13/work/ INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAN3=		Apache.3 Apache::Constants.3  Apache::ExtUtils.3 \
		Apache::FakeRequest.3 Apache::Leak.3 \
		Apache::Log.3 Apache::Options.3 \
		Apache::PerlRun.3 Apache::PerlRunXS.3 \
		Apache::RedirectLogFix.3 \
		Apache::Registry.3 Apache::SizeLimit.3 \
		Apache::Status.3 Apache::Symbol.3 Apache::Symdump.3 \
		Apache::Table.3 Apache::URI.3 Apache::Util.3 \
		Apache::httpd_conf.3 Apache::src.3 Bundle::Apache.3 \
		Apache::Debug.3 mod_perl.3 Apache::SIG.3 Apache::Resource.3 \
		Apache::RegistryLoader.3 Apache::StatINC.3 Apache::Include.3 \
		Apache::PerlSections.3 cgi_to_mod_perl.3 \
		mod_perl_cvs.3 mod_perl_method_handlers.3 mod_perl_traps.3 \
		mod_perl_tuning.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

post-install:
		${MKDIR} ${PREFIX}/share/doc/mod_perl
		${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/mod_perl
		@ ${SETENV} ${MAKE_ENV} PORTSDIR=${PORTSDIR} ${CONFIGURE_ENV} /usr/bin/perl ${SCRIPTDIR}/install_httpd
.if !defined(BATCH)
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
