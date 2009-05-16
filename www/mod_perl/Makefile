# New ports collection makefile for:	mod_perl
# Date created:				November 5th 1999
# Whom:	      				Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_perl
PORTVERSION=	1.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	ModPerl/GOZER

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Embeds a Perl interpreter in the Apache server

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PORTSCOUT=	limit:^1

USE_APACHE=	1.3
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	USE_APXS=1 EVERYTHING=1 INSTALLSITELIB=${SITE_PERL} \
			INSTALLSITEARCH=${SITE_PERL}/${PERL_ARCH} \
			WITH_APXS=${APXS} \
			PERL_EXTRA_CFLAGS='-DDEFAULT_PATH=\"/bin:/usr/bin:/usr/local/bin\"'

MAN3=		Apache.3 Apache::Constants.3  Apache::ExtUtils.3 \
		Apache::FakeRequest.3 Apache::File.3 Apache::Leak.3 \
		Apache::Log.3 Apache::MyConfig.3 Apache::Options.3 \
		Apache::PerlRun.3 Apache::PerlRunXS.3 \
		Apache::RedirectLogFix.3 \
		Apache::Registry.3 Apache::SizeLimit.3 \
		Apache::Status.3 Apache::Symbol.3 Apache::Symdump.3 \
		Apache::Table.3 Apache::URI.3 Apache::Util.3 \
		Apache::httpd_conf.3 Apache::src.3 Apache::testold.3 \
		Bundle::Apache.3 \
		Apache::Debug.3 mod_perl.3 Apache::SIG.3 Apache::Resource.3 \
		Apache::RegistryLoader.3 Apache::StatINC.3 Apache::Include.3 \
		Apache::PerlSections.3 Apache::fork.3 cgi_to_mod_perl.3 \
		mod_perl_cvs.3 mod_perl_method_handlers.3 mod_perl_traps.3 \
		mod_perl_tuning.3

.if defined(APACHE_PORT)
.  if ${APACHE_PORT:Mipv6} != ""
WITH_APACHE_IPV6=	YES
CFLAGS+=	-DAPACHE6
.  endif
.endif

post-install:
	${MKDIR} ${LOCALBASE}/${APACHEINCLUDEDIR}/modules/perl
	${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
	    ${LOCALBASE}/${APACHEINCLUDEDIR}/modules/perl
	${INSTALL_PROGRAM} ${WRKSRC}/apaci/libperl.so ${LOCALBASE}/${APACHEMODDIR}/
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
