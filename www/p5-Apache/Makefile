# New ports collection makefile for:	p5-Apache
# Version required:			1.07
# Date created:				April 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.11 1998/09/15 21:31:55 asami Exp $
#

DISTNAME=	mod_perl-1.07
PKGNAME=	p5-Apache-1.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/www/apache12:patch

BROKEN=		perl5 upgrade

USE_PERL5=	YES
CONFIGURE_ENV=	APACHEDIR=${WRKDIRPREFIX}${.CURDIR}/../apache12/work INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAN3=		Apache.3 Apache::Constants.3  Apache::Options.3 \
		Apache::Registry.3  Apache::Status.3  Bundle::Apache.3 \
		Apache::Debug.3 mod_perl.3 Apache::SIG.3 Apache::Resource.3 \
		Apache::RegistryLoader.3 Apache::StatINC.3 Apache::Include.3 \
		Apache::PerlSections.3 cgi_to_mod_perl.3 mod_perl_traps.3 \
		mod_perl_tuning.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

post-install:
		${MKDIR} ${PREFIX}/share/doc/mod_perl
		${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/mod_perl
		@ ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} /usr/bin/perl ${SCRIPTDIR}/install_httpd
.if !defined(BATCH)
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
